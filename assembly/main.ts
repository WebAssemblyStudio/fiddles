export function sieveOfEratosthenes(n: i32): Int8Array {
    let sieve = new Int8Array(n);
    for (let i = 0; i < n; i++) {
        sieve[i] = 1;
    }
    sieve[0] = 0;
    sieve[1] = 0;
    for (let i = 2; i < Math.sqrt(n); i++) {
        if (sieve[i]) {
            for (let j = i*i, k = 1; j < n; j = i*i+k*i, k = k+1) {
                sieve[j] = 0;
            }
        }
    }
    return sieve;
}

export function sieveOfEratosthenes2(n: i32): Int8Array {
    let sieve = new Int8Array(n);
    for (let i = 0; i < n; i++) {
        sieve[i] = 1;
    }
    sieve[0] = 0;
    sieve[1] = 0;
    for (let i = 2, len = Math.sqrt(n) as i32; i < len; ++i) {
        let si = i * i;
        if (sieve[i]) {
            for (let j = si, k = 1; j < n; j = si + k * i, ++k) {
                sieve[j] = 0;
            }
        }
    }
    return sieve;
}