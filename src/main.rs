extern {
  fn blink_led(i: i32);
}

#[no_mangle]
pub extern "C" fn blinkALed() -> i32 {
     unsafe
  {
blink_led(1000);  
  }

  return 0xAA;
}