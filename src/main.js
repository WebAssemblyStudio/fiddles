WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  env: {
    log: function(v) {
      console.log(v);
    },
    abort: function(msg, file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  }
}).then(result => {
  const exports = result.instance.exports;

  const test1 = exports.test1;
  const test2 = exports.test2;
  
  console.time('division by constant 10 (mulh/shift)');
  test1();
  console.timeEnd('division by constant 10 (mulh/shift)');

  console.time('division by constant 10 (normal)');
  test2();
  console.timeEnd('division by constant 10 (normal)');

}).catch(console.error);

