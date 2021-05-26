// Current prelude for using `wasm_bindgen`, and this'll get smaller over time!
// #![feature(proc_macro, wasm_custom_section, wasm_import_module)]
// extern crate wasm_bindgen;
// use wasm_bindgen::prelude::*;

trait NumTrait {
  fn num(&self) -> u32;
}

struct One(char);
impl NumTrait for One {
  fn num(&self) -> u32 {
    1
  }
}

struct Two(char);
impl NumTrait for Two {
  fn num(&self) -> u32 {
    1
  }
}

#[inline(never)]
fn dynamic_dispatch(n: &NumTrait) {
  n.num();
}

#[no_mangle]
pub extern fn do_the_thing() {
    let one = One('1');
    let one = &one as &NumTrait;
    dynamic_dispatch(one);
    let two = Two('1');
    let two = &two as &NumTrait;
    dynamic_dispatch(two);
}
