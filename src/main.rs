#[no_mangle]
pub extern fn fib(n: u32) -> u32 {
    match n {
        0 | 1 => 1,
        _ => fib(n - 2) + fib(n - 1),
    }
}