#![feature(proc_macro, wasm_custom_section, wasm_import_module)]
extern crate sha1;
use sha1::{Sha1, Digest};

extern {
  fn logResult(i: i32);
}
#[no_mangle]
pub extern "C" fn add_one(x: i32) {
    unsafe {
      logResult(x + 1);
    }
}

pub extern "C" fn hash_string(x: &str) {
  // read hash digest
  let hex = Sha1::digest_reader(x);
  unsafe {
    logResult(hex);
  }
}