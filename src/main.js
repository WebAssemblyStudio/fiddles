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

  console.time('js pow');
  let acc = 0.0;
  let y = 1.0;
  for (let x = Number.MIN_VALUE; x < 1000000.0; x += 10.3333) {
    acc += Math.pow(x, y);
    y = x * 2.5;
  }
  console.timeEnd('js pow');
}).catch(console.error);
