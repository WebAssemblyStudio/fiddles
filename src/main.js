fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  instance = results.instance;
  const {load_mem, write_mem, mem} = instance.exports;
  console.log("Before write: ", load_mem(0))
  write_mem(0, 1)
  console.log("After write: ", load_mem(0))
  console.log("Dump memory: ", new Uint8Array(mem.buffer, 0, 50));
}).catch(console.error);

