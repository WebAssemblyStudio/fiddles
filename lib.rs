extern {
    fn alert(ptr: *const u8, number: u32);
}

#[no_mangle]
pub extern "C" fn run() {
    unsafe {
        let x = vec![100,200,3,4,5,6,7,8];
        alert(x.as_mut_ptr(), 42);
    }
}
