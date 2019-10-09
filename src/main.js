WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  env: {
    abort(_msg, _file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  },
}).then(result => {
  const exports = result.instance.exports;
  const n = 10000000;

  console.time('t1');
  exports.sieveOfEratosthenes(n);
  console.timeEnd('t1');

  console.time('t2');
  exports.sieveOfEratosthenes2(n);
  console.timeEnd('t2');

}).catch(console.error);
