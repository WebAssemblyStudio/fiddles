extern {
  fn logResult(i: i32);
}

#[no_mangle]
pub extern "C" fn add_one(x: i32) {
  unsafe {
    logResult(x+1);
  }
}