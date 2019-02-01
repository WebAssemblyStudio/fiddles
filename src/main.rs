#[no_mangle]
pub extern "C" fn add(x: i32, y: i32) -> i32 {
    x + y
}

#[no_mangle]
pub extern "C" fn add_overflowing(x: i32, y: i32) -> (i32, bool) {
    x.overflowing_add(y)
}

#[no_mangle]
pub extern "C" fn add_checked(x: i32, y: i32) -> Option<i32> {
    x.checked_add(y)
}