fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  instance = results.instance;
  instance.exports.david();
  heap = instance.exports.memory.buffer;
  buffer = instance.exports.getBuffer();
  name = new Uint32Array(heap, buffer, 8);
  document.getElementById("container").textContent = name;
}).catch(console.error);
