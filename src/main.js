WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  env: {
    abort(_msg, _file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  },
}).then(result => {
  const exports = result.instance.exports;

  const n = 500000000;

  exports.bench1(1000);
  exports.bench1(1000);

  let s = performance.now();
  exports.bench1(n);
  let end = performance.now() - s;

  console.log('bench1: ' + end + ' ms');

  exports.bench2(1000);
  exports.bench2(1000);

  s = performance.now();
  exports.bench2(n);
  end = performance.now() - s;

  console.log('bench2: ' + end + ' ms');
}).catch(console.error);
