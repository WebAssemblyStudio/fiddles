fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  instance = results.instance;

  let buffer_in = new Uint8Array([1, 2, 5, 12, 25])

  document.getElementById("container").textContent = instance.exports.bufferSum();
}).catch(console.error);
