#![feature(proc_macro, wasm_custom_section, wasm_import_module)]

extern crate wasm_bindgen;

use wasm_bindgen::prelude::*;

#[wasm_bindgen]
extern "C" {
    fn alert(s: &str);
    fn printSum(result: &str);

    // type HTMLDocument;
    // type Element;

    // static document: HTMLDocument;

    // #[wasm_bindgen(method)]
    // fn createElement(this: &HTMLDocument, tagName: &str) -> Element;

    // #[wasm_bindgen(method, getter)]
    // fn body(this: &HTMLDocument) -> Element;

    // #[wasm_bindgen(method, js_name = appendChild)]
    // fn append(this: &Element, item: Element);

    // #[wasm_bindgen(method, setter = innerHTML)]
    // fn set_inner(this: &Element, html: &str);
}

#[wasm_bindgen]
pub fn calculator(inputA: i64, inputB: i64)->i64{
    //alert(&format!("Input A {}", inputA));
    inputA+inputB
}

#[wasm_bindgen]
pub fn sumatory() -> i64{
  5+5
    // let result = "result";
    // printSum(&format!("{}", result));
}

// #[wasm_bindgen]
// pub fn run_alert(item: &str) {
//     //alert(&format!("This is WASM and {}", item));

// }

// #[wasm_bindgen]
// pub fn create_stuff() {
//     let div = document.createElement("div");
//     let p = document.createElement("p");

//     p.set_inner("Hello from WASM in Rust!");
//     div.append(p);

//     document.body().append(div);
// }

//Arithmetic operations
/*
fn suma(a: f32, b: f32) -> f32{
    a + b
}
fn subtraction(a: f32, b: f32) -> f32{
    a - b
}
fn multiplication(a: f32, b: f32) -> f32{
    a - b
}
fn division(a: f32, b: f32) -> f32{
    a / b
}
*/
