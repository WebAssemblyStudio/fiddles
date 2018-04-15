fetch('../out/main.wasm').then(bytes => WebAssembly.instantiateStreaming(bytes)).then(results => {
  instance = results.instance;
  document.getElementById("container").innerText = instance.exports.add(1,1);
});
