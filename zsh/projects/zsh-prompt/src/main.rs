use std::{env, vec};

struct PromptSection<'a> {
    text: String,
    visible: bool,
    prefix: &'a String,
    suffix: &'a String,
    left_pad: usize,
    right_pad: usize,
    fill: &'a String,
}

impl<'a> PromptSection<'a> {
    // meant to be used on strings without escapes or decoration
    fn len(&self) -> usize {
        if self.text.is_empty() {
            return 0;
        }
        self.text.len() + 2 + self.right_pad + self.left_pad
    }

    // fill is fill char, pad is where to put fill char (-: left, +: right)
    fn term_text(&self) -> String {
        if !self.visible {
            return String::new();
        }
        format!("{}({}{}{}){}",
            self.fill.repeat(self.left_pad),
            self.prefix,
            self.text,
            self.suffix,
            self.fill.repeat(self.right_pad)
        )
    }
}

struct Prompt<'a> {
    text_vec: Vec<PromptSection<'a>>,
    columns: usize,
    fill: &'a String
}

impl <'a> Prompt<'a> {
    fn len(&self) -> usize {
        let mut len = 0;
        for section in &self.text_vec {
            len += section.len();
        }
        len
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

    let mut prefix = line.clone();
    let mut suffix = line.clone();
    let end_prompt = format!(" {cyan_escape}>{reset_escape} ");

    let line_len: usize;

    let columns: usize;
    let home = get_env_var("HOME");
    let mut python_venv = get_env_var("VIRTUAL_ENV_PROMPT");
    let mut pwd = get_env_var("PWD");
    let mut return_code = get_env_var("RETURN_CODE");
    let mut user = get_env_var("USER");

    let prompt_vec = vec![
        PromptSection {
            text: user,
            visible: true,
            prefix: &cyan_escape,
            suffix: &reset_escape,
            left_pad: 0,
            right_pad: 1,
            fill: &line,
        }
    ];

    // available width
    columns = match get_env_var("COLUMNS").parse::<usize>() {
        Ok(n) => n,
        Err(_e) => 0,
    };

    // current directory (home is replace with ~)
    if pwd.starts_with(&home) {
        pwd.replace_range(0..home.len(), "~");
    }

    // only show return code if it isn't 0
    if return_code == "0" {
        return_code = String::new();
    }

    // prevent prompt overflow
    //if total_prompt_len!() > columns {
    //    pwd = shorten_path(&pwd, 2);
    //
    //if total_prompt_len!() > columns {
    //    user = String::new();
    //
    //if total_prompt_len!() > columns {
    //    python_venv = String::new();
    //
    //if total_prompt_len!() > columns {
    //    return_code = String::new();
    //
    //if total_prompt_len!() > columns {
    //    pwd = shorten_path(&pwd, 1);
    //
    //if total_prompt_len!() > columns {
    //    pwd = shorten_path(&pwd, 0);
    //
    //if total_prompt_len!() > columns {
    //    suffix = String::new();
    //
    //if total_prompt_len!() > columns {
    //    prefix = String::new();
    //}}}}}}}}

    line_len = columns;//if total_prompt_len!() > columns {0} else {columns - total_prompt_len!()};

    print!("{}", prompt_vec[0].prompt_text());
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
