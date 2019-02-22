fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  instance = results.instance;
  
  var offset = instance.exports.getData();
  var linearMemory = new Float32Array(instance.exports.memory.buffer, offset, 16);

  var a = instance.exports.vec2create();
  var b = instance.exports.vec2create();

  console.log(a, b);


}).catch(console.error);
