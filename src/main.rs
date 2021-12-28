
#[no_mangle]
pub extern "C" fn add(x: i32) -> i32 
{
let mut vec = Vec::new();
vec.push(1);
vec.push(2);
  
    x + 1
}

#[no_mangle]
pub extern "C" fn berp(v0: f64, v1: f64, t: f64) -> f64 
{
    (t - v0) / (v1 - v0)
}

#[no_mangle]
pub extern "C" fn lerp(v0: f64, v1: f64, t: f64) -> f64 
{
    (1.0 - t) * v0 + t * v1
}

#[no_mangle]
pub extern "C" fn clamp(min: f64, max: f64, val: f64) -> f64 
{
    if val < min
    {
        min
    } 
    else if val > max 
    {
        max
    } 
    else 
    {
        val
    }
}