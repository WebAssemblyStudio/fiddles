#[no_mangle]
pub extern "C" fn cool_add_one(x: i32) -> String {
    format!("{} is awesome!", x + 1)
}