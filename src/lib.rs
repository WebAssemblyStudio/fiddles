// Current prelude for using `wasm_bindgen`, and this'll get smaller over time!
#![feature(proc_macro, wasm_custom_section, wasm_import_module)]
extern crate wasm_bindgen;
use wasm_bindgen::prelude::*;


fn middle(line: &str, t_len: usize) -> String {
    "|".to_owned()
        + line
        + format!("{:width$}", "", width = t_len - line.len()).as_str()
        + &"|".to_owned()
}

fn top(t_len: usize) -> String {
    let mut hl = String::from("");

    for _ in 0..(t_len) {
        hl.push_str("─")
    }

    format!("{}{}{}", "┌", hl, "┐")
}

fn bottom(t_len: usize) -> String {
    let mut hl = String::from("");

    for _ in 0..(t_len) {
        hl.push_str("─")
    }

    format!("{}{}{}", "└", hl, "┘")
}

fn form_wrap(s: String) -> String {
    let mut r = String::from("");
    let mut max_len = 0;

    let lines = s.lines().into_iter();
    let v = lines.collect::<Vec<&str>>();

    for item in v.iter() {
        if item.len() > max_len {
            max_len = item.len();
        }
    }

    r.push_str((top(max_len) + "\n").as_str());

    for line in v.iter() {
        r.push_str((middle(line, max_len) + "\n").as_str());
    }

    r.push_str((bottom(max_len) + "\n").as_str());

    r
}


// Here we're exporting a function called `greet` which will display a greeting
// for `name` through a dialog.
#[wasm_bindgen]
pub fn boxify(name: &str) -> String {
    form_wrap(name.to_string())
}
