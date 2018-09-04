WebAssembly.instantiateStreaming(fetch('../out/main.wasm')).then(results => {
  instance = results.instance;
  instance.exports.setValue(2,2,1);
  document.getElementById("container").innerText = instance.exports.getValue(2,2);
}).catch(console.error);

