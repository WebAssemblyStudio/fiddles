fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  instance = results.instance;
  exports = instance.exports;

  console.log(exports.myFunction());
  console.log(exports.myFunction().toString(16));

}).catch(console.error);

