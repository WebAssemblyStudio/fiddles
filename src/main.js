fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  instance = results.instance;
  let mem = new WebAssembly.Memory({
    initial: 2
  })
  let mem2 = new WebAssembly.Memory({
    initial: 2
  })
  let heap = new Uint8Array(mem.buffer)
  let heap2 = new Uint8Array(mem2.buffer)
  for (i = 0; i < 100; i++) {
    heap[i] = 0xaa + i;
  }
  instance.exports.show(heap)
  // console.log(heap2)
}).catch(console.error);
