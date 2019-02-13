

WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  env: {
    abort(msg, file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  },
}).then(result => {
  const exports = result.instance.exports;


  console.time('t1');
  for (let i = 0, j = 1000000; i < 1000000; i++, j--) {
    exports.testLogic(i, j);
  }
  console.timeEnd('t1');

  console.time('t2');
  for (let i = 0, j = 1000000; i < 1000000; i++, j--) {
    exports.testLogic2(i, j);
  }
  console.timeEnd('t2');

  console.time('t3');
  for (let i = 0, j = 1000000; i < 1000000; i++, j--) {
    exports.testLogic3(i, j);
  }
  console.timeEnd('t3');

}).catch(console.error);
