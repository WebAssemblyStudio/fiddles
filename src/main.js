(async () => {
  const response = await fetch('../out/test.wasm');
  const module = await WebAssembly.compileStreaming(response);
  const instance = await WebAssembly.instantiate(module);
  const result = instance.exports.addy(42, 2);
  document.getElementById("container").textContent = result;
})();