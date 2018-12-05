fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  instance = results.instance;
  instance.exports.setBuffer(24);
  heap = instance.exports.memory.buffer;
  buffer = instance.exports.getBuffer();
  data = new Uint32Array(heap, buffer, 24);
  data.set([100, 97, 118, 255, 105, 100, 0, 255]);
  instance.exports.greyscale();
  document.getElementById("container").textContent = name;
}).catch(console.error);
