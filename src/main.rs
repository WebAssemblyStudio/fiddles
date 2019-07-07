#[no_mangle]
pub extern "C" fn add_one(x: i32)  {
  unsafe {
  logResult(x * 2)
    }
}
extern{
  fn logResult(i: i32);
}
