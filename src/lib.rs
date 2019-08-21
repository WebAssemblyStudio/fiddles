// Current prelude for using `wasm_bindgen`, and this'll get smaller over time!
#![feature(proc_macro, wasm_custom_section, wasm_import_module)]
extern crate js_sys;
extern crate wasm_bindgen;
use wasm_bindgen::prelude::*;


// Here we're importing the `alert` function from the browser, using
// `#[wasm_bindgen]` to generate correct wrappers.
#[wasm_bindgen]
extern {
    fn alert(s: &str);
    type HTMLDocument;
    static document: HTMLDocument;
    #[wasm_bindgen(method, js_name = createElement)]
    fn create_element(this: &HTMLDocument, tagName: &str) -> Element;
  
    #[wasm_bindgen(method, getter)]
    fn body(this: &HTMLDocument) -> Element;

    type Element;
    #[wasm_bindgen(method, setter = innerHTML)]
    fn set_inner_html(this: &Element, html: &str);
    #[wasm_bindgen(method, js_name = appendChild)]
    fn append_child(this: &Element, other: &Element); 
    
    #[wasm_bindgen(method, js_name = querySelector)]
    fn query_selector(this: &HTMLDocument, selector: &str) -> Element;
    #[wasm_bindgen(method, js_name = querySelectorAll)]
    fn query_selector_all(this: &HTMLDocument, selector: &str) -> NodeList;

    // Import NodeList/Node and their properties/methods
    type NodeList;
    #[wasm_bindgen(method)]
    fn item(this: &NodeList, index: u32) -> Option<Node>;

    type Node;
}

// Here we're exporting a function called `greet` which will display a greeting
// for `name` through a dialog.
#[wasm_bindgen]
pub fn greet(name: &str) {
    alert(&format!("Hello, {}!", name));
}
// Here we're exporting a function called `add_one` which will display a greeting
// for `name` through a dialog.
#[wasm_bindgen]
pub fn add_one(x: u32) {
  let mut y=0;
  y=x+1;
  let s = y.to_string();
  let div = document.create_element("div");
  let div2= document.query_selector(".myclass");
 
  div2.set_inner_html(&s);
  document.body().append_child(&div2); 

  

}
