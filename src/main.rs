#![feature(proc_macro, wasm_custom_section, wasm_import_module)]
extern crate wasm_bindgen;
use wasm_bindgen::prelude::*;

#[wasm_bindgen]
pub fn greet(name: &str) -> String {
  //alert("Hello from Rust!")

  let greeting:String = format!("Hello, {}!", name);
  alert(&greeting);

  // semicolon is not needed because it is an expression
  // or in other words, this is return value and ";" is not needed 
  // because ";" is supressing expression
  greeting
}

#[wasm_bindgen]
extern {
  fn alert(s: &str);

  #[wasm_bindgen(js_namespace = console)]
  fn log(s: &str);

  #[wasm_bindgen(js_namespace = console, js_name = log)]
  fn console_log_u32(n: u32);
}