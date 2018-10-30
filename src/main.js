WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  env: {
    abort(msg, file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  },
}).then(result => {
  const exports = result.instance.exports;
  
  console.time('as original');
  var acc1 = exports.original();
  console.timeEnd('as original');
  console.log("as original acc: " + acc1);

  console.time('as new');
  var acc3 = exports.newVersion();
  console.timeEnd('as new');
  console.log("as new acc: " + acc3);

  var acc2 = 0.0;
  console.time('js');
  for (let x = 1e-60; x < 1e60; x *= 1.00001) {
    acc2 += Math.exp(x) * 1e-60;
  }
  console.timeEnd('js');
  console.log("js acc: " + acc2);

}).catch(console.error);
