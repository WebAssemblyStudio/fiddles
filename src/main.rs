#[no_mangle]
pub extern "C" fn add_one(x: i32) -> i32 {
    x + 1
}

#[no_mangle]
pub extern "C" fn add(a: i32, b: i32) -> i32 {
    return a + b
}

#[no_mangle]
pub extern "C" fn minus(a: i32, b: i32) -> i32 {
    return a - b
}