fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  let instance = results.instance;
  let heap = instance.exports.memory.buffer;

  let size = 8;
  instance.exports.setSize(size);
  let buffer = instance.exports.getBuffer();

  let data = new Uint32Array(heap, buffer, size);
  data.set([100, 97, 118, 255, 105, 100, 0, 255]);
  //instance.exports.greyscale();
  document.getElementById("container").textContent = data;
}).catch(console.error);
