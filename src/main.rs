use std::ffi::CString;
use std::fmt::Write;

extern {
  fn update_html(_:i32, _:i32);
}

struct Model {
  count: i32
}
static mut state: Option<Model> = None;

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

    ($w:ident ({ for $nodes:expr } $($tail:tt)*)) => {
        for node in $nodes {
          write!($w, "{}", node);
        }
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
    Some(ref x) => x,
    None => panic!(),
  }
}

unsafe fn view() -> String {
  let Model {count} = getModel();
  html!(
    <button>{"-"}</button>
    {count}
    <button>{"+"}</button>
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
pub unsafe extern "C" fn init() {
  state = Some(Model {
    count: 0
  });
  render();
}