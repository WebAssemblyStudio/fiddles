fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes, {
  io: {
    print: console.log
  }
})).then(results => {
  let instance = results.instance;
  // instance is your webassembly module
  let asm = instance.exports;
  // asm is an object with all the items that you exported
  console.log (asm.run());
}).catch(console.error);


