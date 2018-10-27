WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  main: {
  },
  env: {
    abort(msg, file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  },
}).then(result => {
  const exports = result.instance.exports;
  console.time('wasm');
  const res1 = exports.test();
  console.timeEnd('wasm');
  console.log('res1: ', res1);

  console.time('js');
  let res2 = 0;

  let acc = 0.0;
  for (let i = 0.0; i < 10000000.0; ++i) {
    acc += ((i / 10000000.0) % acc);
  }
  res2 = acc;
  console.timeEnd('js');
  console.log('res2: ', res2);
}).catch(console.error);
