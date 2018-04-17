use std::ffi::CString;
struct Model {
  input: String,
  todos: Vec<String>,
}
static mut state: Option<Model> = None;


extern "C" {
  fn log(_: i32, _:i32);
}

#[no_mangle]
pub unsafe extern "C" fn hello_world() {
  let string = "Hello World!";
  state = Some(Model {
    input: "test".to_string(),
    todos: !vec[]
  });
  let s = CString::new(string).unwrap();
  let offset = s.into_raw() as i32;
  let length = string.len() as i32;
  log(offset, length);
}