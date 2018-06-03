#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
long fib(long n) {
  // compute recursively
  if (n < 3) return 1;
  else return fib(n-1) + fib(n-2);
}

long memo_fib(long n, long * memo) {
  // base cases
  if (n < 3) return 1;

  // check memo and return if already computed
  long found = memo[n];
  if (found) return found;

  // compute and memoize
  found = memo_fib(n-1, memo) + memo_fib(n-2, memo);
  memo[n] = found;

  return found;
}

WASM_EXPORT
long memoize(long n) {
  // wrapper for memo_fib
  long memo[n+1];

  // initialize memo to all 0's
  for (long i = 0; i <= n; i++)
    memo[i] = 0;

  return memo_fib(n, memo);
}

WASM_EXPORT
long tabulate(long n) {
  long arr[n+1];

  // initialize base cases
  arr[0] = 0;
  arr[1] = 1;

  // tabulate all results up to n
  for (long i = 2; i <= n; i++)
    arr[i] = arr[i-1] + arr[i-2];

  return arr[n];
}
