#[repr(C)]
struct Rgb {
  r: u8,
  g: u8,
  b: u8,
}

extern {
  fn submit_rgb(rgb: *mut Rgb, amt: usize);
}

#[no_mangle]
pub extern fn run() {
    let mut dst = Vec::new();
    for x in 0..100 {
      dst.push(Rgb { r: x, g: x, b: x });
    }
    unsafe {
      submit_rgb(dst.as_mut_ptr(), dst.len());
    }
}