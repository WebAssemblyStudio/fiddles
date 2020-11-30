WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  env: {
    abort(_msg, _file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  },
}).then(result => {
  const exports = result.instance.exports;
  console.log('uopt(1.0, NaN): ' + exports.uopt(1.0, NaN));
  console.log('opt(1.0, NaN): ' + exports.opt(1.0, NaN));
}).catch(console.error);
