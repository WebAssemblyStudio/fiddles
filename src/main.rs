

#[no_mangle]
pub extern "C" fn add_one(x: i32) -> i32 {
    x + 2
}

#[no_mangle]
pub extern "C" fn do_stuff(x: i32, y: i32) -> i32 {
    x + y
}
