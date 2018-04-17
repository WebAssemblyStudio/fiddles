use std::ffi::CString;
struct Model {
  input: String,
  todos: Vec<String>,
}

extern "C" {
  fn log(_: i32, _:i32);
}

#[no_mangle]
pub unsafe extern "C" fn hello_world() {
  static mut state: Model = Model {
    input: "".to_string(),
    todos: vec![],
  };
  let string = "Hello World!";
  let s = CString::new(string).unwrap();
  let offset = s.into_raw() as i32;
  let length = string.len() as i32;
  log(offset, length);
}