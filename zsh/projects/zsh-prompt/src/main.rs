use std::{env, vec};

mod prompt {

    #[derive(PartialEq)]
    pub enum Align {
        Left,
        Center,
        Right,
    }

    #[derive(PartialEq)]
    pub enum PromptType {
        Text,
        Path,
    }

    pub struct PromptSection<'a> {
        pub text: String,
        pub prompt_type: PromptType,
        pub visible: bool,
        // determines when section is hidden (paths are shortened at 20 and 10)
        pub visibility_priority: usize,
        pub prefix: &'a String,
        pub suffix: &'a String,
        pub align: Align,
        pub left_pad: usize,
        pub right_pad: usize,
    }

    impl<'a> PromptSection<'a> {
        // meant to be used on strings without escapes or decoration
        fn len(&self) -> usize {
            if self.visible && !self.text.is_empty() {
                return self.text.len() + 2 + self.right_pad + self.left_pad;
            }
            0
        }
    }

    pub struct Prompt<'a> {
        pub sections: Vec<PromptSection<'a>>, // assumes align order is correct
        pub prompt_section: PromptSection<'a>,
        pub columns: usize,
        pub fill: &'a String
    }

    impl <'a> Prompt<'a> {
        pub fn len(&self) -> usize {
            let mut len = 0;
            for section in &self.sections {
                len += section.len();
            }
            len
        }

        fn fit_prompt(&mut self) {
            if self.len() <= self.columns {
                return
            }
            let mut visibility_order_i: Vec<usize> = Vec::new();
            let mut path_i: Vec<usize> = Vec::new(); // store an index for every path in the sections

            // sort lowest visibility levels to the front
            let mut vis_ord = self.sections.iter().enumerate().collect::<Vec<_>>();
            vis_ord.sort_by(|a, b| (b.1.visibility_priority - a.1.visibility_priority).cmp(&b.1.visibility_priority));

            // store indices in new vectors
            for section_enum in vis_ord.iter() {
                visibility_order_i.push(section_enum.0.clone());
                if section_enum.1.prompt_type == PromptType::Path {
                    path_i.push(section_enum.0);
                }
            }

            let mut is_two_dir = false;
            let mut is_one_dir = false;
            let mut is_zero_dir = false;
            for section_i in visibility_order_i {
                if self.len() <= self.columns { break }
                if !is_zero_dir && self.sections[section_i].visibility_priority < 10 {
                    is_zero_dir = true;
                    for p_i in &path_i {
                        self.sections[*p_i].text = self.shorten_path(&self.sections[*p_i].text, 0);
                    }
                    if self.len() <= self.columns { break }
                }
                else if !is_one_dir && self.sections[section_i].visibility_priority < 20 {
                    is_one_dir = true;
                    for p_i in &path_i {
                        self.sections[*p_i].text = self.shorten_path(&self.sections[*p_i].text, 1);
                    }
                    if self.len() <= self.columns { break }
                }
                else if !is_two_dir && self.sections[section_i].visibility_priority < 30 {
                    is_two_dir = true;
                    for p_i in &path_i {
                        self.sections[*p_i].text = self.shorten_path(&self.sections[*p_i].text, 2);
                    }
                    if self.len() <= self.columns { break }
                }
                self.sections[section_i].visible = false;
            }
        }

        fn shorten_path(&self, path: &String, long_levels: usize) -> String {
            let mut new_path_vec: Vec<String> = path.split('/').map(|s| s.to_string()).collect();
            let short_levels = if long_levels < new_path_vec.len() {new_path_vec.len() - long_levels} else {new_path_vec.len()};
            for i in 0..short_levels {
                new_path_vec[i] = new_path_vec[i].chars().next().unwrap_or_default().to_string();
            }
            new_path_vec.join("/")
        }

        pub fn term_text(&mut self) -> String {
            let mut prompt = String::new();
            let mut left_done = false;
            let mut center_done = false;

            self.fit_prompt();

            let len = self.len();
            let line_columns = if self.columns > len {self.columns - len} else {0};
            let left_columns = (line_columns / 2) + (line_columns % 2);
            let right_columns = line_columns / 2;

            for section in &self.sections {
                if !left_done && section.align != Align::Left {
                    left_done = true;
                    prompt += &self.fill.repeat(left_columns);
                }
                if left_done && !center_done && section.align != Align::Center {
                    center_done = true;
                    prompt += &self.fill.repeat(right_columns);
                }
                if section.visible && !section.text.is_empty() {
                    prompt += &format!("{}({}{}{}){}",
                        self.fill.repeat(section.left_pad),
                        section.prefix,
                        section.text,
                        section.suffix,
                        self.fill.repeat(section.right_pad)
                    );
                }
            }
            prompt += &format!("{}{}{}", 
                self.prompt_section.prefix,
                self.prompt_section.text,
                self.prompt_section.suffix,
            );
            prompt
        }
    }
}

fn main() {
    let reset_escape: String;
    let italic_escape: String;
    let red_escape: String;
    let green_escape: String;
    let blue_escape: String;
    let cyan_escape: String;
    let line = String::from("\u{2500}");

    if env::args().any(|arg| arg == "-z") { // zsh
        reset_escape = String::from("%{\x1B[0m%}");
        italic_escape = String::from("%{\x1B[3m%}");
        red_escape = String::from("%{\x1B[31m%}");
        green_escape = String::from("%{\x1B[32m%}");
        blue_escape = String::from("%{\x1B[34m%}");
        cyan_escape = String::from("%{\x1B[36m%}");
    }
    else {
        reset_escape = String::from("\x1B[0m");
        italic_escape = String::from("\x1B[3m");
        red_escape = String::from("\x1B[31m");
        green_escape = String::from("\x1B[32m");
        blue_escape = String::from("\x1B[32m");
        cyan_escape = String::from("\x1B[36m");
    }

    let blue_italic = format!("{}{}", italic_escape, blue_escape);

    let columns_env: usize;
    let home = get_env_var("HOME");
    let return_code = get_env_var("RETURN_CODE");
    let mut pwd = get_env_var("PWD");

    // available width
    columns_env = match get_env_var("COLUMNS").parse::<usize>() {
        Ok(n) => n,
        Err(_e) => 0,
    };

    if pwd.starts_with(&home) {
        pwd.replace_range(0..home.len(), "~");
    }

    let mut prompt = prompt::Prompt {
        sections: vec![
            // return code
            prompt::PromptSection {
                visible: return_code != "0",
                text: return_code,
                prompt_type: prompt::PromptType::Text,
                visibility_priority: 25,
                prefix: &red_escape,
                suffix: &reset_escape,
                align: prompt::Align::Center,
                left_pad: 1,
                right_pad: 1,
            },
            // current working directory
            prompt::PromptSection {
                text: pwd,
                prompt_type: prompt::PromptType::Path,
                visible: true,
                visibility_priority: 40,
                prefix: &green_escape,
                suffix: &reset_escape,
                align: prompt::Align::Right,
                left_pad: 0,
                right_pad: 1,
            },
            // python venv
            prompt::PromptSection {
                text: get_env_var("VIRTUAL_ENV_PROMPT"),
                visible: true,
                prompt_type: prompt::PromptType::Text,
                visibility_priority: 11,
                prefix: &blue_italic,
                suffix: &reset_escape,
                align: prompt::Align::Right,
                left_pad: 0,
                right_pad: 1,
            },
            // user
            prompt::PromptSection {
                text: get_env_var("USER"),
                prompt_type: prompt::PromptType::Text,
                visible: true,
                visibility_priority: 29,
                prefix: &cyan_escape,
                suffix: &reset_escape,
                align: prompt::Align::Right,
                left_pad: 0,
                right_pad: 1,
            },
        ],
        prompt_section: prompt::PromptSection {
            text: String::from(" > "),
            prompt_type: prompt::PromptType::Text,
            visible: true,
            visibility_priority: 0,
            prefix: &cyan_escape,
            suffix: &reset_escape,
            align: prompt::Align::Left,
            left_pad: 0,
            right_pad: 0,
        },
        columns: columns_env,
        fill: &line,
    };

    print!("{}", prompt.term_text());
}


fn get_env_var(name: &str) -> String {
    match env::var(&name) {
        Ok(s) => s,
        Err(_e) => String::new(),
    }
}
