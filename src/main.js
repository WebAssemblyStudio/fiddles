WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  env: {
    abort(msg, file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  },
}).then(result => {
  const exports = result.instance.exports;
  
  console.time('test1');
  const r1 = exports.test1();
  console.timeEnd('test1');
  console.log('r1:', r1);

  console.time('test2');
  const r2 = exports.test2();
  console.timeEnd('test2');
  console.log('r2:', r2);

  console.time('js');
  var acc = 0.0;
  for (let b = 0.0, p = -1000000.0; b < 10000.0; b += 0.001, p += 0.1) {
    acc += Math.pow(b, p);
  }
  console.timeEnd('js');
  console.log('js:', acc);
}).catch(console.error);
