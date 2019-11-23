// Current prelude for using `wasm_bindgen`, and this'll get smaller over time!
#![feature(proc_macro, wasm_custom_section, wasm_import_module)]
extern crate wasm_bindgen;
use wasm_bindgen::prelude::*;

// Here we're importing the `alert` function from the browser, using
// `#[wasm_bindgen]` to generate correct wrappers.
#[wasm_bindgen]
extern {
    fn alert(s: &str);
}

// Here we're exporting a function called `greet` which will display a greeting
// for `name` through a dialog.
#[wasm_bindgen]
pub fn greet() -> u8 {
  16
}

fn dec_to_hex_string(val: u8) -> String {
	let hex_table: [char; 16] = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'];
	let mut hex_string = String::from("");
	let mut x = val;

	while x > 0 {
		let index: u8 = (x % 16);

		hex_string = format!("{}{}", hex_table[index as usize], hex_string);

		x = x / 16;
	}
	
	hex_string
}

#[wasm_bindgen]
pub fn rgb2hex(rgb: Vec<u8>) -> String {
  let mut hex_color = String::from("#");

	for &color in rgb.iter() {
		let mut hex_number = dec_to_hex_string(color);
		
		if hex_number.len() == 1 {
			hex_number = format!("{}{}", "0", hex_number);
		}

		hex_color = format!("{}{}", hex_color, hex_number);
	}

	hex_color
}