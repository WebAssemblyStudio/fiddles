

export function generate_sieve(n: i32): void {
	let isPrime = new Array<bool>(n + 1).fill(true);

	unchecked(isPrime[0] = false);
	unchecked(isPrime[1] = false);
	unchecked(isPrime[2] = true);

	for (let i = 2; i <= n; i++) {
		if (unchecked(isPrime[i])) {
			for (let j = 2; i * j <= n; j ++) {
				unchecked(isPrime[i * j] = false);
			}
		}
	}
}