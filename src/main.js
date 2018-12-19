WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  env: {
    abort(msg, file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  },
}).then(result => {
  const exports = result.instance.exports;
  
  exports.init(4096, 4096);

  // warm up
  exports.test_fast();
  exports.test_fast();
  exports.test_fast();
  exports.test_fast();

  // actual measure
  console.time('cached globals');
  exports.test_fast();
  console.timeEnd('cached globals');

  // warm up
  exports.test_slow();
  exports.test_slow();
  exports.test_slow();
  exports.test_slow();

  // actual measure
  console.time('globals');
  exports.test_slow();
  console.timeEnd('globals');

}).catch(console.error);
