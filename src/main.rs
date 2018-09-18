#[no_mangle]
pub extern fn fib(n: u32) -> f64 {
    let mut a = 1f64;
    let mut b = 1f64;
    for _ in 0..n - 1 {
        let c = a;
        a = b;
        b = c + b;
    }
    a
}