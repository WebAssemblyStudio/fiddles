WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  env: {
    abort(_msg, _file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  },
}).then(result => {
  const exports = result.instance.exports;

  const n = 50_000_000;

  for (let i = 0; i < n / 1000; i++) {
    exports.isPowOf2_1(i);
  }

  let t = performance.now();
  for (let i = 0; i < n; i++) {
    exports.isPowOf2_1(i);
  }
  t = performance.now() - t;
  console.log('isPowOf2_1: ' + t + ' ms');


   for (let i = 0; i < n / 1000; i++) {
    exports.isPowOf2_2(i);
  }

  t = performance.now();
  for (let i = 0; i < n; i++) {
    exports.isPowOf2_2(i);
  }
  t = performance.now() - t;
  console.log('isPowOf2_1: ' + t + ' ms');
}).catch(console.error);
