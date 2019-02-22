function bench() {
  var acc = 0.0;
  for (let i = 0; i < 421657440; i++) {
  // for (let i = 0; i < 0.5; i += (1.0 / 421657440)) {
    acc += Math.fround(Math.sin(Math.fround(i)));
  }
  return acc;
}

WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  main: {
    logSin(angle, x) {
      console.log(angle, x);
    }
  },
  env: {
    abort(msg, file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  },
}).then(result => {
  const exports = result.instance.exports;
  
  exports.bench();
  exports.bench();
  exports.bench();
  exports.bench();

  console.time('as');
  const acc1 = exports.bench();
  console.timeEnd('as');
  console.log('as res: ' + acc1);

  console.time('js');
  const acc = bench();
  console.timeEnd('js');
  console.log('js res: ' + acc);

}).catch(console.error);
