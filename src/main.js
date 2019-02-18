function sin(x) {
  // return Math.sin(x);
  return Math.fround(Math.sin(Math.fround(x)));
}

WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  main: {
    logf(val) {
      console.log("f32: " + val);
    }, 
    logSin(arg, x) {
      console.log(arg, x, sin(arg), Math.abs(x - sin(arg)));
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
  for (let i = 0; i < 421657440 / 10; i++) {
    js += sin(i);
  }
  console.timeEnd('js t');
  console.log('js res', js);
}).catch(console.error);
