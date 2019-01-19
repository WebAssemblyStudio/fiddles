WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  env: {
    abort(msg, file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  },
}).then(result => {
  const exports = result.instance.exports;
  console.time('t1');
  exports.test1(10);
  console.timeEnd('t1');

  console.time('t2');
  exports.test2(10);
  console.timeEnd('t2');

  console.time('t3');
  exports.test3(10);
  console.timeEnd('t3');
}).catch(console.error);
