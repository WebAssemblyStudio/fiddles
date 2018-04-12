extern crate wright;
use wright::version::VERSION;

#[no_mangle]
pub extern "C" fn add_one(x: i32) -> i32 {
    x + 1
}

#[no_mangle]
pub extern "C" fn get_str() -> &'static str {VERSION}