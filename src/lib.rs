#![feature(proc_macro, wasm_custom_section, wasm_import_module)]
extern crate wasm_bindgen;
use wasm_bindgen::prelude::*;

#[wasm_bindgen]
extern "C" {
    type HTMLDocument;
    type Element;

    static document: HTMLDocument;

    #[wasm_bindgen(method)]
    fn createElement(this: &HTMLDocument, tagName: &str) -> Element;
    
    #[wasm_bindgen(method, getter)]
    fn body(this: &HTMLDocument) -> Element;

    #[wasm_bindgen(method, js_name = appendChild)]
    fn append(this: &Element, item: Element);

    #[wasm_bindgen(method, setter = innerHTML)]
    fn set_inner(this: &Element, html: &str);
}

#[wasm_bindgen]
pub fn sum(sumA: f64, sumB: f64)->f64{
    sumA + sumB
}

#[wasm_bindgen]
pub fn subtraction(subtractionA: f64, subtractionB: f64)->f64{
    subtractionA - subtractionB
}

#[wasm_bindgen]
pub fn footer(){
  let div =  document.createElement("div");
  let p   =  document.createElement("p");

  p.set_inner("
  <div class='footer'>
    Adrián Miranda A.
    <br>
    <a href='https://www.twitter.com/heyaparicio' target='_blank'>Twitter</a>
    <br>
    <a href='https://www.linkedin.com/in/heyaparicio' target='_blank'>Linkedin</a>
    <br>
    <a href='https://www.radarez.com' target='_blank'>Radarez.com</a>
    <br>
    <a href='https://www.radarez.com.mx' target='_blank'>Radarez.com.mx</a>
  </div> ");

  div.append(p);
  document.body().append(div);
}
