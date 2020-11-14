fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  const exports = results.instance.exports;
  console.log(exports.test1());
  console.log(exports.test2());
  console.log(exports.test3());
}).catch(console.error);

