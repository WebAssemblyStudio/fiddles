fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  const exports = results.instance.exports;
  console.log(exports.pass(41n));
}).catch(console.error);
