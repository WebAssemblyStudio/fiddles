#![feature(proc_macro, wasm_custom_section, wasm_import_module)]
extern crate wasm_bindgen;
use wasm_bindgen::prelude::*;

#[wasm_bindgen]
pub fn fibonacci_reccursive(n: i32) -> i32 {
	if n < 0 {
		panic!("{} is negative!", n);
	}
	match n {
		0     => panic!("zero is not a right argument to fibonacci_reccursive()!"),
		1 | 2 => 1,
		3     => 2,
		/*
		50    => 12586269025,
		*/
		_     => fibonacci_reccursive(n - 1) + fibonacci_reccursive(n - 2)
	}
}
