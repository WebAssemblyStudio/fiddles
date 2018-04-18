use std::ffi::CString;

extern {
  fn update_html(_:i32, _:i32);
}

unsafe fn update(string: &str) {
  let length = string.len() as i32;
  let cstring = CString::new(string).unwrap();
  let offset = cstring.into_raw() as i32;
  update_html(offset, length);
}

#[no_mangle]
pub unsafe extern "C" fn init() {
  update("<h1>Hello</h1>");
}