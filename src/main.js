fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  const exports = results.instance.exports;
  console.log('actual (1e11): ' + (exports.f64_to_u32(1e11) >>> 0));
  console.log('expected (1e11): 4294967295');
}).catch(console.error);
