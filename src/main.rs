extern "C" {
  fn wasm_log(start:usize,len:usize);
}

fn log(msg:&str){
  let start = msg.as_ptr();
  let len = msg.len();
  unsafe {
      wasm_log(start as usize,len);
  }
}

#[no_mangle]
pub fn wasm_malloc(len: usize) -> *mut u8 {
  let mut buf = Vec::with_capacity(len);
  let ptr = buf.as_mut_ptr();
  std::mem::forget(buf);
  ptr
}

#[no_mangle]
pub fn main(start:*mut u8,len:usize) {
  let bytes = unsafe { Vec::from_raw_parts(start,len,len) };
  let name = std::str::from_utf8(&bytes).unwrap();
  log(&format!("hello {}!",name));
}