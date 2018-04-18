use std::ffi::CString;

extern {
  fn update_html(_:i32, _:i32);
}

unsafe fn view() -> String {
  "<h1>Hello</h1>".to_string()
}

unsafe fn render() {
  let string = view();
  let length = string.len() as i32;
  let cstring = CString::new(string).unwrap();
  let offset = cstring.into_raw() as i32;
  update_html(offset, length);
}

#[no_mangle]
pub unsafe extern "C" fn init() {
  render();
}