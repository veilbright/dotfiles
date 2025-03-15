use std::{env, vec};

mod prompt {

    #[derive(PartialEq)]
    pub enum Align {
        Left,
        Center,
        Right,
    }

    pub struct PromptSection<'a> {
        pub text: String,
        pub visible: bool,
        pub prefix: &'a String,
        pub suffix: &'a String,
        pub align: Align,
        pub left_pad: usize,
        pub right_pad: usize,
    }

    impl<'a> PromptSection<'a> {
        // meant to be used on strings without escapes or decoration
        fn len(&self) -> usize {
            if self.visible {
                return self.text.len() + 2 + self.right_pad + self.left_pad;
            }
            0
        }
    }

    pub struct Prompt<'a> {
        pub text_sections: Vec<PromptSection<'a>>, // assumes align order is correct
        pub prompt_section: PromptSection<'a>,
        pub columns: usize,
        pub fill: &'a String
    }

    impl <'a> Prompt<'a> {
        pub fn len(&self) -> usize {
            let mut len = 0;
            for section in &self.text_sections {
                len += section.len();
            }
            len
        }

        pub fn term_text(&self) -> String {
            let mut prompt = String::new();
            let mut left_done = false;
            let mut center_done = false;
            let line_columns = self.columns - self.len();
            let left_columns = (line_columns / 2) + (line_columns % 2);
            let right_columns = line_columns / 2;

            for section in &self.text_sections {
                if !left_done && section.align != Align::Left {
                    left_done = true;
                    prompt += &self.fill.repeat(left_columns);
                }
                if !center_done && section.align != Align::Center {
                    center_done = true;
                    prompt += &self.fill.repeat(right_columns);
                }
                if section.visible {
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
    let red_escape: String;
    let green_escape: String;
    let blue_escape: String;
    let cyan_escape: String;
    let line = String::from("\u{2500}");

    if env::args().any(|arg| arg == "-z") { // zsh
        reset_escape = String::from("%{\x1B[0m%}");
        red_escape = String::from("%{\x1B[31m%}");
        green_escape = String::from("%{\x1B[32m%}");
        blue_escape = String::from("%{\x1B[34m%}");
        cyan_escape = String::from("%{\x1B[36m%}");
    }
    else {
        reset_escape = String::from("\x1B[0m");
        red_escape = String::from("%{\x1B[31m%}");
        green_escape = String::from("\x1B[32m");
        blue_escape = String::from("\x1B[32m");
        cyan_escape = String::from("\x1B[36m");
    }

    let columns_env: usize;
    let home = get_env_var("HOME");
    let python_venv = get_env_var("VIRTUAL_ENV_PROMPT");
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

    let prompt = prompt::Prompt {
        text_sections: vec![
            prompt::PromptSection {
                visible: return_code != "0",
                text: return_code,
                prefix: &red_escape,
                suffix: &reset_escape,
                align: prompt::Align::Left,
                left_pad: 1,
                right_pad: 0,
            },
            prompt::PromptSection {
                text: pwd,
                visible: true,
                prefix: &green_escape,
                suffix: &reset_escape,
                align: prompt::Align::Right,
                left_pad: 0,
                right_pad: 1,
            },
            prompt::PromptSection {
                text: get_env_var("USER"),
                visible: true,
                prefix: &cyan_escape,
                suffix: &reset_escape,
                align: prompt::Align::Right,
                left_pad: 0,
                right_pad: 1,
            },
        ],
        prompt_section: prompt::PromptSection {
            text: String::from(" > "),
            visible: true,
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

// returns a path string with n directories shortened to 1 letter
fn shorten_path(path: &String, long_levels: usize) -> String {
    let mut new_path_vec: Vec<String> = path.split('/').map(|s| s.to_string()).collect();
    let short_levels = if long_levels < new_path_vec.len() {new_path_vec.len() - long_levels} else {new_path_vec.len()};
    for i in 0..short_levels {
        new_path_vec[i] = new_path_vec[i].chars().next().unwrap_or_default().to_string();
    }
    new_path_vec.join("/")
}

fn get_env_var(name: &str) -> String {
    match env::var(&name) {
        Ok(s) => s,
        Err(_e) => String::new(),
    }
}
