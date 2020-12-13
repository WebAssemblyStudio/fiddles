WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  env: {
    abort(_msg, _file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  },
}).then(result => {
  const exports = result.instance.exports;

  exports.init();

  let t = performance.now();
  exports.benchOriginalMapLookup();
  t = performance.now() - t;

  console.log('Original lookup: ' + t + ' ms');

  t = performance.now();
  exports.benchNewMapLookup();
  t = performance.now() - t;

  console.log('New lookup: ' + t + ' ms');
}).catch(console.error);
