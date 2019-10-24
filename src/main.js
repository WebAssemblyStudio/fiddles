WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  env: {
    abort(_msg, _file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  },
}).then(result => {
  const exports = result.instance.exports;
  console.time('pow2');
  for (let i = 0; i < 20000000; i++) {
    exports.pow2(i);
  }
  console.timeEnd('pow2');

  console.time('pow2 fast');
  for (let i = 0; i < 20000000; i++) {
    exports.pow2fast(i);
  }
  console.timeEnd('pow2 fast');
}).catch(console.error);
