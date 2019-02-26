const rust = import('../out/main.wasm');

rust
  .then(m => m.generate_greeting())
  .catch(console.error);

fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  const instance = results.instance;
  const wasm = instance.exports;
  const memory = instance.exports.memory;
  let i = instance.exports.hello_world();
  const ret = wasm.generate_greeting();
  let buffer = new Uint8Array(memory.buffer, i, instance.exports.hello_world_len());
  console.log(i, ret);
  let str = String.fromCharCode(...buffer);
  document.getElementById("txt").textContent = str;
  document.getElementById("container").textContent = instance.exports.add_one(41);
}).catch(console.error);
