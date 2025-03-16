use std::env::{self};

use decoration::Align;

mod prompt {

    #[derive(PartialEq, Clone, Copy)]
    pub enum Align {
        Left = -1,
        Center = 0,
        Right = 1,
    }

    #[derive(PartialEq)]
    pub enum PromptType {
        Text,
        Path,
    }

    pub struct PromptSection {
        pub text: String,
        pub icon: String,
        pub prompt_type: PromptType,
        pub visible: bool,
        pub icon_visible: bool,
        // determines when section is hidden (lower is hidden first) (paths are shortened at 30,20,10)
        pub visibility_priority: usize,
        pub prefix: String,
        pub suffix: String,
        pub align: Align,
    }

    impl PromptSection {
        // meant to be used on strings without escapes or decoration
        fn len(&self) -> usize {
            let mut len = 0;
            if self.is_visible() {
                len += self.text.chars().count();
            }
            if self.icon_is_visible() {
                len += self.icon.chars().count();
            }
            len
        }

        fn is_visible(&self) -> bool {
            self.visible && !self.text.is_empty()
        }
        fn icon_is_visible(&self) -> bool {
            self.icon_visible&& !self.icon.is_empty()
        }
    }

    pub struct Prompt {
        pub sections: Vec<PromptSection>, // assumes align order is correct
        pub prompt_section: PromptSection,
        pub section_right_boundary: String,
        pub section_left_boundary: String,
        pub prefix: String,
        pub suffix: String,
        pub section_pad: usize,
        pub surround_section_pad: bool,
        pub columns: usize,
        pub section_fill: String,
        pub blank_fill: String,
    }

    impl Prompt {
        pub fn len(&self) -> usize {
            let mut len = self.prefix.chars().count() + self.suffix.chars().count();
            let mut left_aligned = 0; // number of sections aligned
            let mut center_aligned = 0;
            let mut right_aligned = 0;
            let alignment_padding_modifier: isize = match self.surround_section_pad {
                true => 1, // _section_section_
                false => -1, // section_section
            };

            let mut visible_section_iter = self.sections.iter().filter(|s| s.is_visible()).peekable();
            while let Some(section) = visible_section_iter.next() {
                len += section.len() + self.section_left_boundary.chars().count() + self.section_right_boundary.chars().count();
                match section.align {
                    Align::Left => left_aligned += 1,
                    Align::Center => center_aligned += 1,
                    Align::Right => right_aligned += 1,
                }
            }
            if left_aligned > 0 {
                len += (self.section_fill.chars().count() as isize *
                self.section_pad as isize *
                (left_aligned as isize + alignment_padding_modifier))
                as usize;
            }
            if center_aligned > 0 {
                len += (self.section_fill.chars().count() as isize *
                self.section_pad as isize *
                (center_aligned as isize + alignment_padding_modifier))
                as usize;
            }
            if right_aligned > 0 {
                len += (self.section_fill.chars().count() as isize *
                self.section_pad as isize *
                (right_aligned as isize + alignment_padding_modifier))
                as usize;
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
            vis_ord.sort_by(|a, b| (b.1.visibility_priority as isize - a.1.visibility_priority as isize).cmp(&(b.1.visibility_priority as isize)));

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
            let mut prompt = self.prefix.clone();
            let mut current_align: Option<Align> = None;

            self.sections.sort_by_key(|s| s.align as isize);
            self.fit_prompt();

            let len = self.len();
            let line_columns = if self.columns > len {self.columns - len} else {0};
            let left_columns = (line_columns / 2) + (line_columns % 2);
            let right_columns = line_columns / 2;

            let mut visible_section_iter = self.sections.iter().filter(|s| s.is_visible()).peekable();
            while let Some(section) = visible_section_iter.next() {
                let pad_prefix = self.surround_section_pad && (current_align.is_none() || current_align.unwrap() != section.align);
                if current_align.is_none() {
                    current_align = Some(Align::Left);
                }

                // alignment and padding code, it's bad
                if pad_prefix && section.align == Align::Left {
                    prompt += &self.section_fill.repeat(self.section_pad);
                }
                if section.align != Align::Left && (current_align.is_none() || current_align.unwrap() == Align::Left) {
                    current_align = Some(Align::Center);
                    prompt += &self.blank_fill.repeat(left_columns);
                }
                if pad_prefix && section.align == Align::Center {
                    prompt += &self.section_fill.repeat(self.section_pad);
                }
                if section.align == Align::Right && (current_align.is_none() || current_align.unwrap() == Align::Center) {
                    current_align = Some(Align::Right);
                    prompt += &self.blank_fill.repeat(right_columns);
                }
                if pad_prefix && section.align == Align::Right {
                    prompt += &self.section_fill.repeat(self.section_pad);
                }

                // prompt section formatting
                if section.icon_is_visible() {
                    prompt += &format!("{}{}{}{}{}{}",
                        self.section_left_boundary,
                        section.prefix,
                        section.icon,
                        section.text,
                        section.suffix,
                        self.section_right_boundary,
                    );
                }
                else {
                    prompt += &format!("{}{}{}{}{}",
                        self.section_left_boundary,
                        section.prefix,
                        section.text,
                        section.suffix,
                        self.section_right_boundary,
                    );
                }
                if self.surround_section_pad ||
                (self.blank_fill.is_empty() && visible_section_iter.peek().is_some()) ||
                visible_section_iter.peek().is_some_and(|s| s.align == section.align) {
                    prompt += &self.section_fill.repeat(self.section_pad);
                }
            }
            match current_align.unwrap_or_else(|| Align::Left) {
                Align::Left => prompt += &format!("{}{}", self.blank_fill.repeat(left_columns), self.blank_fill.repeat(right_columns)),
                Align::Center => prompt += &self.blank_fill.repeat(right_columns),
                Align::Right => (),
            };
            prompt += &format!("{}{}{}{}",
                self.suffix,
                self.prompt_section.prefix,
                self.prompt_section.text,
                self.prompt_section.suffix,
            );
            prompt
        }
    }
}

mod decoration {
    pub struct Decoration {
        pub prompt_indicator: String,
        pub prompt_prefix: String,
        pub prompt_suffix: String,
        pub icon_visible: bool,
        pub blank_fill: String,
        pub section_left_boundary: String,
        pub section_right_boundary: String,
        pub section_pad: usize,
        pub surround_section_pad: bool,
        pub section_fill: String,
        pub align: Align,
        pub reset_section: String,
        pub italic_section: String,
        pub red_section: String,
        pub green_section: String,
        pub yellow_section: String,
        pub blue_section: String,
        pub magenta_section: String,
        pub cyan_section: String,
        pub white_section: String,
    }

    pub enum Theme {
        Default,
        Line,
        Powerline,
        Pureline,
    }

    pub enum Align {
        Left,
        Right,
    }
}

enum Shell {
    Bash,
    Zsh,
}


fn main() {
    let mut shell = Shell::Bash;
    let mut theme = decoration::Theme::Default;
    let mut decoration = decoration::Decoration {
        prompt_indicator: String::from("  "),
        prompt_prefix: String::new(),
        prompt_suffix: String::new(),
        icon_visible: false,
        section_left_boundary: String::new(),
        section_right_boundary: String::new(),
        section_pad: 1,
        surround_section_pad: false,
        section_fill: String::from(" "),
        blank_fill: String::new(),
        align: Align::Left,
        reset_section: String::new(),
        italic_section: String::new(),
        red_section: String::new(),
        green_section: String::new(),
        yellow_section: String::new(),
        blue_section: String::new(),
        magenta_section: String::new(),
        cyan_section: String::new(),
        white_section: String::new(),
    };

    let mut args = env::args().skip(1);
    while let Some(arg) = args.next() {
        match &arg[..] {
            "-s" => {
                let value = parse_opt(&arg, args.next()).trim().to_lowercase();
                shell = match &value[..] {
                    "bash" => Shell::Bash,
                    "zsh" => Shell::Zsh,
                    _ => panic!("Unknown value for option '-s'")
                };
            },
            "-t" => {
                let value = parse_opt(&arg, args.next()).trim().to_lowercase();
                theme = match &value[..] {
                    "line" => decoration::Theme::Line,
                    "pureline" => decoration::Theme::Pureline,
                    _ => panic!("Unknown value for option '-t'")
                }
            },
            "-a" => {
                let value = parse_opt(&arg, args.next()).trim().to_lowercase();
                decoration.align = match &value[..] {
                    "left" => decoration::Align::Left,
                    "right" => decoration::Align::Right,
                    _ => panic!("Unknown value for option '-a'")
                }
            }
            "-i" => decoration.icon_visible = true,
            _ => panic!("Unknown arg: '{arg}'"),
        };
        fn parse_opt(arg: &String, opt: Option<String>) -> String {
            match opt {
                Some(o) => o,
                None => panic!("No option provided for {arg}"),
            }
        }
    }

    match shell {
        Shell::Bash => {
            decoration.reset_section = String::from("\x1B[0m");
            decoration.italic_section = String::from("\x1B[3m");
            decoration.red_section = String::from("\x1B[31m");
            decoration.green_section = String::from("\x1B[32m");
            decoration.blue_section = String::from("\x1B[34m");
            decoration.cyan_section = String::from("\x1B[36m");
        }
        Shell::Zsh => {
            decoration.reset_section = String::from("%{\x1B[0m%}");
            decoration.italic_section = String::from("%{\x1B[3m%}");
            decoration.red_section = String::from("%{\x1B[31m%}");
            decoration.green_section = String::from("%{\x1B[32m%}");
            decoration.blue_section = String::from("%{\x1B[34m%}");
            decoration.cyan_section = String::from("%{\x1B[36m%}");
        }
    }

    match theme {
        decoration::Theme::Default => (),
        decoration::Theme::Line => {
            decoration.section_left_boundary = String::from("(");
            decoration.section_right_boundary = String::from(")");
            decoration.prompt_prefix = String::from("\u{2500}");
            decoration.prompt_suffix = String::from("\u{2500}");
            decoration.section_pad = 1;
            decoration.section_fill = String::from("\u{2500}");
            decoration.blank_fill = String::from("\u{2500}");
        },
        decoration::Theme::Powerline => (),
        decoration::Theme::Pureline => {
            decoration.prompt_prefix = String::from("\u{2500}");
            decoration.prompt_suffix = String::from("\u{2500}");
            decoration.section_pad = 1;
            decoration.surround_section_pad = true;
            decoration.section_fill = String::from(" ");
            decoration.blank_fill = String::from("\u{2500}");
        },
    };

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
        columns: columns_env,
        section_left_boundary: decoration.section_left_boundary,
        section_right_boundary: decoration.section_right_boundary,
        section_pad: decoration.section_pad,
        surround_section_pad: decoration.surround_section_pad,
        prefix: decoration.prompt_prefix,
        suffix: decoration.prompt_suffix,
        section_fill: decoration.section_fill,
        blank_fill: decoration.blank_fill,
        prompt_section: prompt::PromptSection {
            text: decoration.prompt_indicator,
            icon: Default::default(),
            prompt_type: prompt::PromptType::Text,
            visible: true,
            icon_visible: false,
            visibility_priority: 0,
            prefix: decoration.cyan_section.clone(),
            suffix: decoration.reset_section.clone(),
            align: prompt::Align::Left,
        },
        sections: vec![
            // return code
            prompt::PromptSection {
                visible: return_code != "0",
                text: return_code,
                icon: String::from(" "),
                icon_visible: true,
                prompt_type: prompt::PromptType::Text,
                visibility_priority: 25,
                prefix: decoration.red_section.clone(),
                suffix: decoration.reset_section.clone(),
                align: prompt::Align::Center,
            },
            // current working directory
            prompt::PromptSection {
                text: pwd,
                icon: String::from("  "),
                visible: true,
                icon_visible: decoration.icon_visible,
                prompt_type: prompt::PromptType::Path,
                visibility_priority: 40,
                prefix: decoration.green_section.clone(),
                suffix: decoration.reset_section.clone(),
                align: decoration_to_prompt_align(&decoration.align),
            },
            // python venv
            prompt::PromptSection {
                text: get_env_var("VIRTUAL_ENV_PROMPT"),
                icon: String::from("󰌠  "),
                visible: true,
                icon_visible: decoration.icon_visible,
                prompt_type: prompt::PromptType::Text,
                visibility_priority: 11,
                prefix: format!("{}{}", decoration.blue_section, decoration.italic_section),
                suffix: decoration.reset_section.clone(),
                align: decoration_to_prompt_align(&decoration.align),
            },
            // user
            prompt::PromptSection {
                text: get_env_var("USER"),
                icon: String::from("  "),
                prompt_type: prompt::PromptType::Text,
                visible: true,
                icon_visible: decoration.icon_visible,
                visibility_priority: 29,
                prefix: decoration.cyan_section.clone(),
                suffix: decoration.reset_section.clone(),
                align: decoration_to_prompt_align(&decoration.align),
            },
        ],
    };

    print!("{}", prompt.term_text());

    fn get_env_var(name: &str) -> String {
        match env::var(&name) {
            Ok(s) => s,
            Err(_e) => String::new(),
        }
    }
    fn decoration_to_prompt_align(align: &decoration::Align) -> prompt::Align {
        match align {
            Align::Left => prompt::Align::Left,
            Align::Right => prompt::Align::Right,
        }
    }
}


