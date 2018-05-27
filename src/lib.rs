// Current prelude for using `wasm_bindgen`, and this'll get smaller over time!
#![feature(proc_macro, wasm_custom_section, wasm_import_module)]
extern crate wasm_bindgen;
use wasm_bindgen::prelude::*;
// Globally available JS functions (eg. defined on window object)
// can be declared here.
#[wasm_bindgen]
extern {
    fn jslogger(s: &str);
}

#[wasm_bindgen]
pub fn hello(greeting: String, number: u32) -> String {
  let answer = number * 2;
  format!("
    <p>
      {} from wasm! the answer is {}!
    </p>
  ", greeting, answer)
}

// A struct is available as a JS class.
#[wasm_bindgen]
pub struct Cat {
  name: String,
  age: u32
}

#[wasm_bindgen]
impl Cat {
  pub fn new(name: String, age: u32) -> Cat {
    jslogger("constructing a cat!");
    Cat { name, age }
  }

  pub fn describe(&self) -> String {
    format!("{} year(s) old cat named {}", self.age, self.name)
  }
}
