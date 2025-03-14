use std::env;

macro_rules! get_prompt_len {
     ($($str:expr),*) => {
             {
             let len = 0;
             $(
                let len = len + get_prompt_len(&$str);
             )*
             len
         }
     };
 }

fn main() {
    let reset_escape = String::from("\x1B[0m");
    let cyan_escape = String::from("\x1B[36m");
    let green_escape = String::from("\x1B[32m");

    let end_prompt = format!(" {cyan_escape}>{reset_escape} ");

    let line_len: usize;

    let columns: usize;
    let mut user = get_env_var("USER");
    let home = get_env_var("HOME");
    let mut pwd: String = get_env_var("PWD");

    columns = match get_env_var("COLUMNS").parse::<usize>() {
        Ok(n) => n,
        Err(_e) => 0,
    };

    // current directory (home is replace with ~)
    if pwd.starts_with(&home) {
        pwd.replace_range(0..home.len(), "~");
    }

    // prevent prompt overflow
    if get_prompt_len!(pwd, user) > columns {
        pwd = shorten_path(&pwd, Some(2));
    }
    if get_prompt_len!(pwd, user) > columns {
        user = String::new();
    }
    if get_prompt_len!(pwd, user) > columns {
        pwd = shorten_path(&pwd, Some(1));
    }
    if get_prompt_len!(pwd, user) > columns {
        pwd = shorten_path(&pwd, None);
    }

    line_len = if get_prompt_len!(pwd, user) > columns {0} else {columns - get_prompt_len!(pwd, user)};

    // output prompt
    print!("{}{}{}{}",
        "\u{2500}".repeat(line_len),
        to_prompt_str(&pwd, Some(&green_escape)),
        to_prompt_str(&user, Some(&cyan_escape)),
        end_prompt,
    );
}

// returns a path string with n directories shortened to 1 letter
fn shorten_path(path: &String, long_levels: Option<usize>) -> String {
    let mut new_path_vec: Vec<String> = path.split('/').map(|s| s.to_string()).collect();
    for i in 0..new_path_vec.len() - long_levels.unwrap_or_default() {
        new_path_vec[i] = new_path_vec[i].chars().next().unwrap_or_default().to_string();
    }
    new_path_vec.join("/")
}

fn to_prompt_str(str: &String, ansi_escape: Option<&String>) -> String {
    if str.is_empty() {
        return String::new();
    }
    if let Some(ansi) = ansi_escape {
        format!("({ansi}{str}\x1B[0m)\u{2500}")
    }
    else {
       format!("({str})\u{2500}")
    }
}

fn get_env_var(name: &str) -> String {
    match env::var(&name) {
        Ok(s) => s,
        Err(_e) => String::new(),
    }
}

// meant to be used on strings without escapes or decoration
fn get_prompt_len(str: &String) -> usize {
    if !str.is_empty() {
        return str.len() + 3;
    }
    0
}

fn term_string_len(str: &String) -> usize {
    let mut len = 0;
    let mut term_escape = false;

    for c in str.chars() {
        if term_escape == false {
            if c == '\x1B' { // enter term escape
                term_escape = true;
            }
            else {
                len += 1;
            }
        }
        else if c == 'm' { // exit term escape
            term_escape = false;
        }
    }
    len
}
