WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  main: {
    logf(v) {
      console.log(v);
    }
  },
  env: {
    abort(msg, file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  },
}).then(result => {
  const exports = result.instance.exports;
  console.time('original Math.pow');
  exports.test1();
  console.timeEnd('original Math.pow');

  console.time('new pow');
  exports.test2();
  console.timeEnd('new pow');
}).catch(console.error);
