let wasmPromise = fetch('../out/main.wasm');

WebAssembly.instantiateStreaming(wasmPromise)
.then(results => {
  let instance = results.instance;
  document.getElementById("container").textContent = instance.exports.my_func();
}).catch(console.error);
