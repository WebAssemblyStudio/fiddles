WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  env: {
    abort(msg, file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  },
}).then(result => {
  const exports = result.instance.exports;
  exports.bench1();
  exports.bench1();
  exports.bench1();

  console.time('t1');
  exports.bench1();
  console.timeEnd('t1');

  exports.bench2();
  exports.bench2();
  exports.bench2();

  console.time('t2');
  exports.bench2();
  console.timeEnd('t2');
}).catch(console.error);
