(async () => {
  const fetchPromise = fetch('../out/main.wasm');
  const { instance } = await WebAssembly.instantiateStreaming(fetchPromise);
  document.getElementById("container").textContent = instance.exports.ofp(1,2);
})();

