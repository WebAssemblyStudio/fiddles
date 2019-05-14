
#![feature(proc_macro, wasm_custom_section, wasm_import_module)]
extern crate wasm_bindgen;
use wasm_bindgen::prelude::*;

#[wasm_bindgen]
extern {
    fn alert(s: &str);
}

#[wasm_bindgen]
pub fn greet(name: &str) {
    alert(&format!("Hello, {}!", name));
}

fn find_fibonacci(n: usize) -> i64 {
  let mut f:Vec<i64> = vec![0, 1];
  for i in 2..n + 1 {
    let next_f = f[i - 1] + f[i - 2];
    f.push(next_f)
  }
  return f[n];
}

#[wasm_bindgen]
pub fn fibonacci(n: usize) -> i64 {
  let ans: i64 = find_fibonacci(n);
  ans
}
