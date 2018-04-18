#![allow(unused)]
use std::ffi::CString;
use std::fmt::Write;
pub mod html;

extern "C" {
  fn update(_: i32, _:i32);
}
static mut state: Option<Model> = None;

struct Model {
  count: i32
}

macro_rules! write_html {
    ($w:ident) => (());
    
    ($w:ident ()) => (());

    ($w:ident ($e:tt)) => (write!($w, "{}", $e));
    
    ($w:ident (< $tag:ident > $($tail:tt)*)) => {
        write!($w, "<{}>", stringify!($tag));
        write_html!($w ($($tail)*) );
    };
    
    ($w:ident (< / $tag:ident > $($tail:tt)*)) => {
        write!($w, "</{}>", stringify!($tag));
        write_html!($w ($($tail)*) );
    };

    ($w:ident ({ $e:expr } $($tail:tt)*)) => {
        write!($w, "{}", $e);
        write_html!($w ($($tail)*) );
    };
}

macro_rules! html {
    ($($tail:tt)*) => {{
        let mut out = String::new();
        write_html!(out ($($tail)*));
        out
    }}
}

unsafe fn view() -> String {
  match state {
    Some(Model { count }) => {
      html!(
        <div>
          <button>{"-"}</button>
          { count + 2 }
          <button>{"+"}</button>
        </div>
      )
    }
    None => {
      "oops".to_owned()
    }
  }
}

#[no_mangle]
pub unsafe extern "C" fn event(id: i32) {

}

#[no_mangle]
pub unsafe extern "C" fn init() {
  state = Some(Model {
    count: 12,
  });
  view();
  state = Some(Model {
    count: 13,
  });
  view();
  let string = view();
  let length = string.len() as i32;
  let s = CString::new(string.as_str()).unwrap();
  let offset = s.into_raw() as i32;
  update(offset, length);
}
