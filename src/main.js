// This is our recommended way of loading WebAssembly.
// https://developers.google.com/web/updates/2018/04/loading-wasm
(async () => {
  const fetchPromise = fetch('../out/fibonacci.wasm');
  const { instance } = await WebAssembly.instantiateStreaming(fetchPromise);
  const result = instance.exports.fibonacci(40);
  document.querySelector('main').textContent = `The 40nd Fibonacci number is ${ result }.`;
})();