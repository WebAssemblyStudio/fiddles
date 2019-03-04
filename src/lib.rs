// Current prelude for using `wasm_bindgen`, and this'll get smaller over time!
#![feature(proc_macro, wasm_custom_section, wasm_import_module)]
extern crate wasm_bindgen;
use wasm_bindgen::prelude::*;

pub struct Store {
  up_count:i8,
  down_count:u8
}

impl Store {
  pub fn decrement(&mut self) -> u8 {
    self.down_count = self.down_count - 1;
    self.down_count
  }

  pub fn increment(&mut self) -> i8 {
    self.up_count = self.up_count + 1;
    self.up_count
  }
}

static mut store: Store = Store {
  down_count: 0, up_count: 0
};

#[wasm_bindgen]
pub fn decrement() -> u8 {
  unsafe {
    let d = store.decrement();
    d
  }
}

#[wasm_bindgen]
pub fn increment() -> i8 {
  unsafe {
    let d = store.increment();
    d
  }
}