
(async () => {
  const fetchPromise = fetch('../out/ggt.wasm');
  const { instance } = await WebAssembly.instantiateStreaming(fetchPromise);
  const result = instance.exports.primes();
  document.querySelector('main').textContent = `Amount ${ result }`;
   
})();