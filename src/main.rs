
extern "C" {
  fn imported_func(x: str);
  fn new_js_string(utf8: *const u8, len: i32) -> i32;
  fn console_log(js: i32);
}

fn rs2js(rs: &str) -> i32 {
  assert!(rs.len() < i32::max_value() as usize);
  unsafe { new_js_string(rs.as_ptr(), rs.len() as i32) }
}

#[no_mangle]
pub extern fn test() {
  unsafe {
    // imported_func(&s1);
    console_log(rs2js("Hello 123 again!"));
    console_log(rs2js("2222"));
  }
}
