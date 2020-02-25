WebAssembly.instantiateStreaming(fetch('../out/main.wasm')).then(obj => {
  document.getElementById("container").textContent = obj.instance.exports.add(30,40);
});

