#[no_mangle]
pub extern "C" fn add_one(x: i32) -> i32 {
    x + 1
}

pub extern "C" fn sum(x: i32, y: i32) -> i32 {
    x + y
}
