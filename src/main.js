WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  env: {
    abort(msg, file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  },
}).then(result => {
  const exports = result.instance.exports;

  exports.init();
  exports.test1();
  exports.test1();
  exports.test1();
  exports.test1();

  exports.init();

  console.time('t1');
  exports.test1();
  console.timeEnd('t1');

  exports.init();
  exports.test2();
  exports.test2();
  exports.test2();
  exports.test2();

  exports.init();

  console.time('t2');
  exports.test2();
  console.timeEnd('t2');
}).catch(console.error);
