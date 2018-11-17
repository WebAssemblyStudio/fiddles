fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  instance = results.instance;


  // JAVASRIPT FIBONACCI IMPLEMENTATIONS 

  function fib(n) {
    // compute recursively
    if (n < 2) return n;
    else return fib(n-1) + fib(n-2);
  }


  function memo_fib(n, memo) {
    // base cases
    if (n < 3) return 1;

    // check memo and return if already computed
    var found = memo[n];
    if (found) return found;

    // compute and memoize
    found = memo_fib(n-1, memo) + memo_fib(n-2, memo);
    memo[n] = found;

    return found;
  }

  function memoize(n) {
    // wrapper for memo_fib
    var memo = [];

    // initialize memo to all 0's
    for (i = 0; i <= n; i++)
      memo[i] = 0;

    return memo_fib(n, memo);
  }


function tabulate(n) {
  var arr = [];

  // initialize base cases
  arr[0] = 0;
  arr[1] = 1;

  // tabulate all results up to n
  for (i = 2; i <= n; i++)
    arr[i] = arr[i-1] + arr[i-2];

  return arr[n];
}


  // TEST CASES

  // fibonacci number to compute
  const n = 45;
 
  // straightforward recursive webassembly implemenation
  let wasmFibStart = performance.now();
  let wasmFibResult = instance.exports.fib(n);
  wasmFibTime = performance.now() - wasmFibStart;
  let wasmFibOut = "★ webassembly recursion computed ".concat(wasmFibResult, " in ", wasmFibTime, "ms");

  // webassembly memoized implemenation
  let wasmMemoStart = performance.now();
  let wasmMemoResult = instance.exports.memoize(n);
  wasmMemoTime = performance.now() - wasmMemoStart;
  let wasmMemoOut = "★ webassembly memoization computed ".concat(wasmMemoResult, " in ", wasmMemoTime, "ms");

  // webassembly tabular implemenation
  let wasmTabulateStart = performance.now();
  let wasmTabulateResult = instance.exports.tabulate(n);
  wasmTabulateTime = performance.now() - wasmTabulateStart;
  let wasmTabulateOut = "★ webassembly tabulation computed ".concat(wasmTabulateResult, " in ", wasmTabulateTime, "ms");

  // straightforward recursive javascript implementation
  let jsFibStart = performance.now();
  let jsFibResult = fib(n);
  jsFibTime = performance.now() - jsFibStart;
  let jsFibOut = "☆ javascript recursion computed ".concat(jsFibResult, " in ", jsFibTime, "ms");

  // javascript memoized implemenation
  let jsMemoStart = performance.now();
  let jsMemoResult = memoize(n);
  jsMemoTime = performance.now() - jsMemoStart;
  let jsMemoOut = "☆ javascript memoization computed ".concat(jsMemoResult, " in ", jsMemoTime, "ms");

  // javascript tabular implemenation
  let jsTabulateStart = performance.now();
  let jsTabulateResult = tabulate(n);
  jsTabulateTime = performance.now() - jsTabulateStart;
  let jsTabulateOut = "☆ javascript tabulation computed ".concat(jsTabulateResult, " in ", jsTabulateTime, "ms");

  // attach results to DOM
  document.getElementById("fibonacci").innerText = "Computing the ".concat(n, "th Fibonacci number:");
  document.getElementById("wasm-recursive").innerText = wasmFibOut;
  document.getElementById("js-recursive").innerText = jsFibOut;
  document.getElementById("wasm-memoize").innerText = wasmMemoOut;
  document.getElementById("js-memoize").innerText = jsMemoOut;
  document.getElementById("wasm-tabulate").innerText = wasmTabulateOut;
  document.getElementById("js-tabulate").innerText = jsTabulateOut;
});