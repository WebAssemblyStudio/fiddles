WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  main: {
    logf(val) {
      console.log("f32: " + val);
    }, 
    logSin(arg, x) {
      console.log(arg, x, Math.sin(arg), Math.abs(x - Math.sin(arg)));
    }
  },
  env: {
    abort(msg, file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  },
}).then(result => {
  const exports = result.instance.exports;
  console.time('as t');
  const as = exports.bench();
  console.timeEnd('as t');
  console.log('as res', as);

  console.time('js t');
  let js = 0;
  for (let i = 0; i < 10000000; i++) {
    js += Math.sin(i * (1.0 / 100));
  }
  console.timeEnd('js t');
  console.log('js res', js);
}).catch(console.error);
