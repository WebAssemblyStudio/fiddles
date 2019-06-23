export function fib(n: f64): f64 {
  let a = 0.0, b = 1.0
	for (let i = 0; i < n; i++) {
		let c = a + b;
		a = b;
		b = c;
	}
	return a;
}
