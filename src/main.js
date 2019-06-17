WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  Math,
  env: {
    abort(_msg, _file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  },
}).then(result => {
  const exports = result.instance.exports;
  const ptr = exports.createMatrix(32,32)
  console.log('Matrix pointer: ' + ptr);
}).catch(console.error);
