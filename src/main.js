
(async () => {
  const fetchPromise = fetch('../out/primes.wasm');
  const { instance } = await WebAssembly.instantiateStreaming(fetchPromise);

  var t0 = performance.now()
  const result = instance.exports.primes();
  var t1 = performance.now()
  console.log("Call to execute WebAssembly Primecounter took " + (t1 - t0) + " milliseconds.")

  document.querySelector('main').textContent = `Amount ${ result }`;

})();