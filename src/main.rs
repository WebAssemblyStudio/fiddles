/*
#[no_mangle]
pub extern "C" fn add_one(x: i32) -> i32 {
    x + 1
}
*/

#[no_mangle]
pub extern "C" fn fibonacci_reccursive(n: i32) -> i32 {
	if n < 0 {
		panic!("{} is negative!", n);
	}
	match n {
		0     => panic!("zero is not a right argument to fibonacci_reccursive()!"),
		1 | 2 => 1,
		3     => 2,
		/*
		50    => 12586269025,
		*/
		_     => fibonacci_reccursive(n - 1) + fibonacci_reccursive(n - 2)
	}
}