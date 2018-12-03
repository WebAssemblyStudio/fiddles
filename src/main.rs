
#[no_mangle]
pub extern "C" fn test(x: f64) -> Result<i64, i64> {
    match x {
      x => Ok(1),
      _ => Err(0)
    }
}