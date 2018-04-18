use std::ffi::CString;
use std::fmt::Write;

extern {
  fn update_html(_:i32, _:i32);
}

struct Model {
  count: i32
}
static mut state: Option<Model> = None;

unsafe fn getModel() -> Model {
  match state {
    Some(x) => x,
    None => panic!(),
  }
}

unsafe fn view() -> String {
  let m = getModel();
  let mut w = String::new();
  write!(w, "<div>{}</div>", m.count);
  w
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
  state = Some(Model {
    count: 0
  });
  render();
}