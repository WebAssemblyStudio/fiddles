(async () => {
  const { instance } = await WebAssembly.instantiateStreaming(fetch('../out/main.wasm'));
  document.getElementById('container').textContent = instance.exports.add_one(41);
})();