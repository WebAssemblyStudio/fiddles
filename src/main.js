fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  const { orig, opt } = results.instance.exports;
  console.log('orig (bits): 0x' + (orig() >>> 0).toString(16));
  console.log('opt (bits): 0x' + (opt() >>> 0).toString(16));
}).catch(console.error);

