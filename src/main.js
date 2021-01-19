
(async () => {
  const fetchPromise = fetch('../out/ggt.wasm');
  const { instance } = await WebAssembly.instantiateStreaming(fetchPromise);
  const result = instance.exports.ggT(12, 18);
  document.querySelector('main').textContent = `ggT of 12 and 18 is ${ result }.`;
  
  for (let i = 0; i < 100; i++) {
    console.log("ggT of " + i + " and " + i + " is " + instance.exports.ggT(i, i));
  }
  
})();