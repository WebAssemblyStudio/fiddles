#[no_mangle]
pub extern "C" fn add_one(x: i32) -> i32 {
    add_more(x)
}

fn add_more(x: i32) -> i32 {
    x + 93
}
