#[no_mangle]
pub extern "C" fn add_one(x: i32) -> f32 {
    add(x,4.14f32) as f32
}

fn add(x: i32, y: f32) -> f32 {
    x as f32 + y
}