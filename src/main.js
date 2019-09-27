WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  main: {
    log(v) {
      console.log('>>> ' + v);
    },
    logChar(c) {
      console.log('chr:' + String.fromCharCode(c));
    }
  },
  env: {
    abort(_msg, _file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  },
}).then(result => {
  const exports = result.instance.exports;

  console.time('test1');
  for (let i = 0; i < 100000; i++) {
    exports.test();
  }
  console.timeEnd('test1');


  console.time('test2');
  for (let i = 0; i < 100000; i++) {
    exports.test2();
  }
  console.timeEnd('test2');
  console.log(exports.test(), exports.test2());
  
}).catch(console.error);
