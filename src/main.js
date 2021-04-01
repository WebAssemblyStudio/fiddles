WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {}).then(result => {
  const exports = result.instance.exports;
  document.getElementById("container").textContent = "Result: " + exports.main(5);
}).catch(console.error);
