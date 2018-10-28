WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  env: {
    abort(msg, file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  },
}).then(result => {
  const exports = result.instance.exports;
  
  console.time('original');
  const res1 = exports.originalConstDiv();
  console.timeEnd('original');
  console.log('original res:', res1);

  console.time('precomputed');
  const res2 = exports.precomputedConstDiv();
  console.timeEnd('precomputed');
  console.log('precomputed res:', res2);
}).catch(console.error);
