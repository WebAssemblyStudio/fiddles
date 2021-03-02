fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  instance = results.instance;
  const mem = new Uint8Array(instance.exports.memory.buffer, 0, 16);
  instance.exports.md5calc(mem);
  document.getElementById("container").textContent = Array.prototype.map.call(mem, byte => (byte & 0xFF).toString(16)).join("");
}).catch(console.error);
