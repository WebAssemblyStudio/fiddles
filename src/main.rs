/*
Chapter 3
#[no_mangle]
pub extern "C" fn add_one(x: i32) -> i32 {
  let result:i32 = x + 1;

  unsafe {
    logResult(result)
  }

  result
}

#[no_mangle]
pub extern "C" fn multiple_two(x: i32) -> i32 {
  let result:i32 = x * 2;

  unsafe {
    logResult(result)
  }

  result
}

extern {
  fn logResult(x: i32);
}
*/

/* Chapter 4 */
use std::ffi::CString;
use std::os::raw::c_char;

#[no_mangle]
pub extern "C" fn getWelcomeMessage() -> *mut c_char {
  CString::new("Hello from Rust!")
    .unwrap()
    .into_raw()
}


#[no_mangle]
pub extern "C" fn dealloc_str(ptr: *mut c_char) {
  unsafe {
    let _ = CString::from_raw(ptr);
  }
}
