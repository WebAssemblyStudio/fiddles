var importObject = { };

WebAssembly.instantiateStreaming(fetch('../out/main.wasm'), importObject).then(results => {
  instance = results.instance;
  document.getElementById("container").innerText = instance.exports.callIndirect(Math.round(Math.random()));
});
