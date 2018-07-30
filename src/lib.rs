// Current prelude for using `wasm_bindgen`
#![feature(proc_macro, wasm_custom_section, wasm_import_module)]
extern crate wasm_bindgen;
use wasm_bindgen::prelude::*;

// Import `alert` from browser, using `#[wasm_bindgen]` to generate correct wrappers.
#[wasm_bindgen]
extern {
    fn alert(s: &str);
}

// Export `greet`
#[wasm_bindgen]
pub fn greet(name: &str) {
    alert(&format!("Hello, {}!", name));
}

#[wasm_bindgen]
pub fn fib(n: i32) -> u64 {
	match n {
		0     => 0,
		1     => 1,
		_     => fib(n - 1) + fib(n - 2)
	}
}













#[wasm_bindgen]
pub fn isFacebookStockGoingToGoUp(n: i32) -> bool {
  return true;
}
