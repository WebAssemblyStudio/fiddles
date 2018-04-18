/*

*/

extern "C" {
  fn log(_: i32, _: i32);
}

#[no_mangle]
pub unsafe extern "C" fn hello_world() {
  log(1, 3)
}