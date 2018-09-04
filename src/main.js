WebAssembly.instantiateStreaming('../out/main.wasm').then(results => {
  instance = results.instance;
  document.getElementById("container").innerText = instance.exports.add(1,1);
}).catch(console.error);

