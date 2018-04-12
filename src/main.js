// This is our recommended way of loading WebAssembly.
(async () => {
  const fetchPromise = fetch('../out/fibonacci.wasm');
  const { instance } = await WebAssembly.instantiateStreaming(fetchPromise);
  const result = instance.exports.fibonacci(42);
  document.querySelector('main').textContent = result;
})();