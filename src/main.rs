#[no_mangle]
pub extern "C" fn fibo(n: u32) -> u32 {
    if n < 2 {
        return 1;
    }
    return fibo(n - 1) + fibo(n - 2);
}