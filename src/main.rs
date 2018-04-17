use std::ffi::CString;

extern "C" {
  fn update(_: i32, _:i32);
}
static mut state: Option<Model> = None;

struct Model {
  count: i32
}

fn view() -> String {
  let s_string = r#"<h1> hey:"#.to_owned() + r#" </h1>"#;
  // + &state.count.to_string() + r#"<h1> hey:"#;
  s_string
}

#[no_mangle]
pub unsafe extern "C" fn init() {
  let string = view();
  state = Some(Model {
    count: 12,
  });
  let length = string.len() as i32;
  let s = CString::new(string).unwrap();
  let offset = s.into_raw() as i32;
  update(offset, length);
}