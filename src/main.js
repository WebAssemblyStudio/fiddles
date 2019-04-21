const memory = new WebAssembly.Memory({ initial: 1 });
fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes, { js: { memory }})).then(results => {
  instance = results.instance;
  const buffer = new Uint32Array(memory.buffer);
  buffer[0] = 10;
  buffer[1] = 20;
  buffer[2] = 30;
  const result = instance.exports.greyscale(0, 3);
  
  console.log(result);
}).catch(console.error);

