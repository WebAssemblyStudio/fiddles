#[no_mangle]
pub extern "C" fn add_one(x: i32) -> i32 {
    x + 1
}

#[no_mangle]
pub extern "C" fn multiply(x: i32, y: i32) -> i32 {
    x * y
}