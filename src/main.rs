#![feature(core_intrinsics, lang_items)]
#![no_main]
#![no_std]

#[lang = "panic_fmt"]
extern "C" fn panic_fmt(_args: ::core::fmt::Arguments, _file: &'static str, _line: u32) -> ! {
  use core::intrinsics;
  unsafe {
    intrinsics::abort();
  }
}


#[no_mangle]
pub extern "C" fn define_and_call_closure(x: i32, y: i32) -> i32 {
  let mut it = x;
  {
    let mut closure_inferred = |i| {
      it += i
    };
    closure_inferred(y);
  }
  it
}