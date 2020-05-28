const chars = [102, 108, 97, 103, 123, 73, 95, 119, 97, 110, 116, 95, 116, 111, 95, 103, 111, 95, 98, 97, 99, 107, 95, 116, 111, 95, 85, 67, 65, 83, 125];

fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  instance = results.instance;
  const heap = new Int32Array(instance.exports.memory.buffer);
  for(let i = 0; i < chars.length; i++) {
    heap[i] = chars[i];
  }
  const result = instance.exports.validate_flag(0, chars.length);
  console.log(result);
}).catch(console.error);
