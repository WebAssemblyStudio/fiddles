// memory in 64kb pages
var memory = new WebAssembly.Memory({ initial: 10 })

fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes, {js: {mem: memory}})).then(results => {
  instance = results.instance;
  var exports = instance.exports;

  mem = new Uint32Array(memory.buffer);

  document.getElementById("container").textContent = instance.exports.add(3,1);
}).catch(console.error);

