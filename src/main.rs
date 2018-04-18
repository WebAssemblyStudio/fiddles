#![allow(unused)]
use std::ffi::CString;
use std::fmt::Write;

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
    
    ($w:ident (< $tag:ident  $($tail:tt)*)) => {
        write!($w, "<{}", stringify!($tag));
        write_html!(@vtag $w ($($tail)*) );
    };

    ($w:ident (@tag onclick={ $e:expr }  $($tail:tt)*)) => {
        write!($w, "<{}>", stringify!($tag));
        write_html!(@tag $w ($($tail)*) );
    };

    (@vtag $w:ident ($attr:ident = { $e:expr }  $($tail:tt)*)) => {
        write!($w, " {}=\"{}\" ", stringify!($attr), $e);
        write_html!(@vtag $w ($($tail)*) );
    };

    (@vtag $w:ident (> $($tail:tt)*)) => {
        write!($w, ">");
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

enum Action {
  Incr = 0,
  Decr = 1,
  Noop,
}

impl Action {
  fn from_i32(n: i32) -> Action {
    match n {
      0 => Action::Incr,
      1 => Action::Decr,
      _ => Action::Noop,
    }
  }
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
      let style = "background: #333; color: red; border-radius: 3px;";
      html!(
        <div>
          <button onclick={"window.rustEvent(1)"} style={style}>{"-"}</button>
          { count }
          <button onclick={"window.rustEvent(0)"} style={style}>{"+"}</button>
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
  match state {
    Some(Model { count }) => {
      match Action::from_i32(id) {
        Action::Incr => {
          state = Some(Model {
            count: count + 1,
          });
        },
        Action::Decr => {
          state = Some(Model {
            count: count - 1,
          });
        },
        _ => ()
      }
      render();
    }
    None => ()
  }
}

unsafe fn render() {
  let string = view();
  let length = string.len() as i32;
  let s = CString::new(string.as_str()).unwrap();
  let offset = s.into_raw() as i32;
  update(offset, length);
}

#[no_mangle]
pub unsafe extern "C" fn init() {
  state = Some(Model {
    count: 0,
  });
  render();
}
