WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  main: {
    log(x) {
      console.log(x);
    }
  },
  env: {
    abort(msg, file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  },
}).then(result => {
  const exports = result.instance.exports;

  for (let i = 0; i < 10; i++) {
    exports.test1(0, 100);
  }
  
  console.time('original min::i32');
  exports.test1(0, 100);
  console.timeEnd('original min::i32');

  for (let i = 0; i < 10; i++) {
    exports.test2(0, 100);
  }

  console.time('new min::i32');
  exports.test2(0, 100);
  console.timeEnd('new min::i32');

}).catch(console.error);
