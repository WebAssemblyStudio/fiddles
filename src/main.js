WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  env: {
    abort(_msg, _file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  },
}).then(result => {
  const exports = result.instance.exports;

  let n;

  n = 10000000;

  console.time('benchOrig (' + n + ')');
  exports.benchOrig(n);
  console.timeEnd('benchOrig (' + n + ')');

  n = 1000000000;

  console.time('benchOrig (' + n + ')');
  exports.benchOrig(n);
  console.timeEnd('benchOrig (' + n + ')');



  n = 10000000;

  console.time('benchNext (' + n + ')');
  exports.benchNext(n);
  console.timeEnd('benchNext (' + n + ')');

  n = 1000000000;

  console.time('benchNext (' + n + ')');
  exports.benchNext(n);
  console.timeEnd('benchNext (' + n + ')');

}).catch(console.error);
