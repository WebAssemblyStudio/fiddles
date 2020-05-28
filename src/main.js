WebAssembly.instantiateStreaming(fetch("../out/main.wasm")).then(result => {
  const exports = result.instance.exports;
  console.log(exports.add(19, 23));
}).catch(console.error);
