WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  env: {
    abort(msg, file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  },
}).then(result => {
  const exports = result.instance.exports;
  
  console.time('original');
  exports.originalConstDiv();
  console.timeEnd('original');

  console.time('precomputed');
  exports.precomputedConstDiv();
  console.timeEnd('precomputed');
}).catch(console.error);
