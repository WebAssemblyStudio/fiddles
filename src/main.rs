#[no_mangle]
pub extern "C" fn fib(x: i32) -> i32 {
    fibonacci(x)
}

pub fn fibonacci(n: i32) -> i32 {
	if n < 0 {
		panic!("{} is negative!", n);
	} else if n == 0 {
		panic!("zero is not a right argument to fibonacci()!");
	} else if n == 1 {
		return 1;
	}

	let mut sum = 0;
	let mut last = 0;
	let mut curr = 1;
	for _i in 1..n {
		sum = last + curr;
		last = curr;
		curr = sum;
	}
	sum
}