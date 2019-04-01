fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  const exports = results.instance.exports;
  const val = BigInt(41);
  console.log(exports.pass(val));
}).catch(console.error);
