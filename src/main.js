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
  
  let res = 0;
  console.time('original minmax::i32');
  res = exports.test1(0, 100);
  console.timeEnd('original minmax::i32');
  console.log('original minmax::i32: ' + res);

  for (let i = 0; i < 10; i++) {
    exports.test2(0, 100);
  }

  console.time('new clamp::i32');
  res = exports.test2(0, 255);
  console.timeEnd('new clamp::i32');
  console.log('original clamp::i32: ' + res);

  
  for (let i = 0; i < 10; i++) {
    exports.test2(0, 255);
  }
}).catch(console.error);