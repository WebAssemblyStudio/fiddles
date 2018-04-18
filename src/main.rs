use std::ffi::CString;
use std::fmt::Write;

extern {
  fn update_html(_:i32, _:i32);
}

struct Model {
  count: i32
}
static mut state: Option<Model> = None;

fn view() -> String {
  match state {
    Some(Model { count }) => {
      let mut w = String::new();
      write!(w, "<div>{}</div>", count);
      w
    },
    None => "No state found".to_string()
  }
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