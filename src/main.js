fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(res => {
  exports = res.instance.exports;
  let mem = exports.memory;
  let bytes = exports.encrypt("test"),
    u32 = new Uint32Array(mem.buffer, bytes, 1),
    ptr = u32[0];
  console.log(new Uint8Array(mem.buffer, ptr, 8));

  // exports.dropBytes(ptr);
}).catch(console.error);
