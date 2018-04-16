use std::ffi::CString;

extern "C" {
  fn log(_:i32, _:i32);
}

#[no_mangle]
pub unsafe extern "C" fn hello_world() {
  let string = "Hello world (from rust!)";
  let s = CString::new(string).unwrap();
  let offset = s.into_raw() as i32;
  let length = string.len() as i32;
  log(offset, length);
}
