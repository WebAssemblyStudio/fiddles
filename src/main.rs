#[no_mangle]
pub extern "C" fn square(a: [i32; 64], b: [i32; 64]) -> i32 {
    a.iter()
        .zip(b.iter()).map(|(&a,&b)| a * b)
        .sum()
}
