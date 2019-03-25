// This is our recommended way of loading WebAssembly.
// https://developers.google.com/web/updates/2018/04/loading-wasm
(async () => {
  const fetchPromise = fetch('../out/fibonacci.wasm');
  const { instance } = await WebAssembly.instantiateStreaming(fetchPromise);
  console.time('WA');
  const result = instance.exports.fibonacci(42);
  console.timeEnd('WA');
  document.querySelector('main').textContent = `The 42nd Fibonacci number is ${ result }.`;
  console.time('js');
  const resultA = fibonacci(42);
  console.timeEnd('js');

  function fibonacci(n) {
    let i, t, a = 0, b = 1;
    for (i = 0; i < n; i++) {
      t = a + b;
      a = b;
      b = t;
    }
    return b;
  }


})();