// Current prelude for using `wasm_bindgen`, and this'll get smaller over time!
#![feature(proc_macro, wasm_custom_section, wasm_import_module)]
extern crate wasm_bindgen;
use wasm_bindgen::prelude::*;

// Here we're importing the `alert` function from the browser, using
// `#[wasm_bindgen]` to generate correct wrappers.
#[wasm_bindgen]
extern {
    fn alert(s: &str);
    fn now() -> i32;
    fn time(s: &str);
    fn timeEnd(s: &str);
    fn log(a: &str, b: &str);
}

// Here we're exporting a function called `greet` which will display a greeting
// for `name` through a dialog.
#[wasm_bindgen]
pub fn greet(name: &str) {
    // alert(&format!("Hello, {}!", name));
    time("rs");
    let n = loopit(10000000000);
    timeEnd("rs");
    log("time", &format!("{}", n));
}

pub fn fib(n: i32) -> i32 {
  if n == 0 {
    return 0;
  } 
  if n == 1 {
    return 1;
  }
  return fib(n - 1) + fib(n - 2);
}

pub fn loopit(n: i32) -> i32 {
  let mut sum = 0;
  for x in 0..n {
    sum += x;
  }
  return sum;
}