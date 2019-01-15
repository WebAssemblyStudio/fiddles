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
    exports.test1();
  }
  
  console.time('original abs::i32');
  exports.test1();
  console.timeEnd('original abs::i32');

  for (let i = 0; i < 10; i++) {
    exports.test2();
  }

  console.time('new abs::i32');
  exports.test2();
  console.timeEnd('new abs::i32');

}).catch(console.error);
