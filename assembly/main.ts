
export function primes_up_to(max: i32): i32[] {
    var sieve = new Array<bool>(max + 1), primes: i32[] = [];
    for (let i = 2; i <= max; ++i) {
        if (!unchecked(sieve[i])) {
            primes.push(i);
            for (let j = i << 1; j <= max; j += i) {
                unchecked(sieve[j] = true);
            }
        }
    }
    return primes;
};