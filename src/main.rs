#[no_mangle]
pub extern "C" fn add_one(x: i32) -> i32 {
    x + 1
}

pub extern "C" fn main() {
    println!("Hello, World!");
}
