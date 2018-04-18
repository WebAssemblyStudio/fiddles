use std::ffi::CString;
use std::fmt::Write;

extern {
  fn update_html(_:i32, _:i32);
}

struct Model {
  count: i32
}
static mut state: Option<Model> = None;

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

macro_rules! write_html {
    ($w:ident) => (());
    
    ($w:ident ()) => (());

    ($w:ident ($e:tt)) => (write!($w, "{}", $e));
    
    ($w:ident (< $tag:ident  $($tail:tt)*)) => {
        write!($w, "<{}", stringify!($tag));
        write_html!(@vtag $w ($($tail)*) );
    };

    (@vtag $w:ident (onclick = { $e:expr }  $($tail:tt)*)) => {
        write!($w, " onclick=\"update({})\" ", $e as i32);
        write_html!(@vtag $w ($($tail)*) );
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

macro_rules! html {
    ($($tail:tt)*) => {{
        let mut out = String::new();
        write_html!(out ($($tail)*));
        out
    }}
}

unsafe fn getModel() -> &'static Model {
  match state {
    Some(ref x) => x.clone(),
    None => panic!(),
  }
}

unsafe fn view() -> String {
  let m = getModel();
  html!(
    <div>
      <button onclick={Action::Decr}>{"-"}</button>
      { m.count }
      <button onclick={Action::Incr}>{"+"}</button>
    </div>
  )
}

unsafe fn render() {
  let string = view();
  let length = string.len() as i32;
  let cstring = CString::new(string).unwrap();
  let offset = cstring.into_raw() as i32;
  update_html(offset, length);
}

#[no_mangle]
pub unsafe extern "C" fn update(id: i32) {
  let m = getModel();
  match Action::from_i32(id) {
    Action::Incr => {
      state = Some(Model {
        count: m.count + 1,
      });
    },
    Action::Decr => {
      state = Some(Model {
        count: m.count - 1,
      });
    },
    _ => ()
  }
  render();
}

#[no_mangle]
pub unsafe extern "C" fn init() {
  state = Some(Model {
    count: 0
  });
  render();
}