mod sub;

#[no_mangle]
pub extern "C" fn sum(limit: u32) -> u32 {
    return sub::sum(limit);
}