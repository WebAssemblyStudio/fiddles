pub enum PrimitiveRaw {
    Empty,
    Point,
    Line,
}

#[no_mangle]
pub extern "C" fn test2(tag: PrimitiveRaw, p0x: f32, p0y: f32, p1x: f32, p1y: f32) -> f32 {
    if let PrimitiveRaw::Point = tag { p0x + p0y } 
    else if let PrimitiveRaw::Line = tag { p0x + p1x } 
    else { 0.0 }
}