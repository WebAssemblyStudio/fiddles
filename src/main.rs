use std::time::Duration;
use std::thread;

#[no_mangle]
pub extern fn sleep() {
    thread::sleep(Duration::from_millis(4000))
}
