@external("env", "lognum")
declare function lognum(num: u32): void;

function isPrime(n: i32): boolean {
    const upperBound = Math.ceil(Math.sqrt(n));
    for(let x = 2; x <= upperBound; x++) {
        if(n % x === 0)
            return false;
    }

    return true;
}

export function run(max: i32): void {
  for(let n = 1; n < max; n++) {
    if(isPrime(n))
        lognum(n);
  }
}