fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  instance = results.instance;

    // fibonacci number to compute
  const n = 45;

  // time call to straightforward fibonacci implemenation
  let fibStart = performance.now();
  let fibResult = instance.exports.fib(n);
  fibTime = performance.now() - fibStart;
  let fibOut = "Recursion only computed ".concat(fibResult, " in ", fibTime, "ms");

  // time call to memoized implemenation
  let memoStart = performance.now();
  let memoResult = instance.exports.memoize(n);
  memoTime = performance.now() - memoStart;
  let memoizeOut = "Memoization computed ".concat(memoResult, " in ", memoTime, "ms");

  // time call to tabular implemenation
  let tabulateStart = performance.now();
  let tabulateResult = instance.exports.tabulate(n);
  tabulateTime = performance.now() - tabulateStart;
  let tabulateOut = "Tabulation computed ".concat(tabulateResult, " in ", tabulateTime, "ms");

  // attach results to DOM
  document.getElementById("fibonacci").innerText = "Computing the ".concat(n, "th Fibonacci number:");
  document.getElementById("recursive").innerText = fibOut;
  document.getElementById("memoize").innerText = memoizeOut;
  document.getElementById("tabulate").innerText = tabulateOut;
});