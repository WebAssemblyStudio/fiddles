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
  
  let t;
  t = performance.now();
  test1();
  t = performance.now() - t;
  console.log('division by uint64 constant 1e10 (mulh/shift): ' + t + ' ms');

  t = performance.now();
  test2();
  t = performance.now() - t;
  console.log('division by uint64 constant 1e10 (normal): ' + t + ' ms');

}).catch(console.error);

