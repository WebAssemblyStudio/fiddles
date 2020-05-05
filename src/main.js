fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  let instance = results.instance;
  // instance is your webassembly module
  let asm = instance.exports;
  // asm is an object with all the items that you exported
  console.log (asm.add(1,1));
}).catch(console.error);

