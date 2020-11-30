WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  env: {
    abort(_msg, _file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  },
}).then(result => {
  const exports = result.instance.exports;
  console.log('uopt(1.0, NaN): 0x' + (exports.uopt(1.0, NaN) >>> 0).toString(16));
  console.log('opt(1.0, NaN):  0x' + (exports.opt(1.0, NaN) >>> 0).toString(16));
}).catch(console.error);
