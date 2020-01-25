fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(res => {
  exports = res.instance.exports;
  let mem = exports.memory;
  let bytes = exports.encrypt("test");
  let u32 = new Uint32Array(mem.buffer, bytes);
  console.log(bytes, new Uint8Array(u32, u32[1], 8));

  // exports.dropBytes(ptr);
}).catch(console.error);
