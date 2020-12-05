// Current prelude for using `wasm_bindgen`, and this'll get smaller over time!
#![feature(proc_macro, wasm_custom_section, wasm_import_module)]
extern crate wasm_bindgen;
use wasm_bindgen::prelude::*;

// Here we're importing the `alert` function from the browser, using
// `#[wasm_bindgen]` to generate correct wrappers.
#[wasm_bindgen]
pub fn tribonacci(n: f64) -> f64 {
	let cbrt_33_mul_3: f64 = 3.0 * 33.0f64.powf(0.5);

	let tribonacci_constant: f64 = 1.0
	+ (19.0 - cbrt_33_mul_3).powf(1.0 / 3.0)
	+ (19.0 + cbrt_33_mul_3).powf(1.0 / 3.0);

	return (
		(tribonacci_constant / 3.0).powf(n - 1.0)
		/ (
			(4.0 / 3.0)
			* tribonacci_constant
			- (1.0 / 9.0)
			* tribonacci_constant.powf(2.0) - 1.0
		)
	).round();
}