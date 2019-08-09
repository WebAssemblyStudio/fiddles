use std::ffi::CString;
use std::os::raw::c_char;

#[no_mangle]
pub extern "C" fn getWelcomeMessage() -> *mut c_char {
    CString::new("Hello World from Rust!")
        .unwrap()
        .into_raw()
}

#[no_mangle]
pub extern "C" fn dealloc_str(ptr: *mut c_char) {
    unsafe {
        let _ = CString::from_raw(ptr);
    }
}