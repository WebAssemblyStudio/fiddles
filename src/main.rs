#[no_mangle]
pub extern fn fib(n: u32) -> u32 {
    let mut a = 1;
    let mut b = 1;
    for _ in 0..n - 1 {
        let c = a;
        a = b;
        b = c + b;
    }
    a
}