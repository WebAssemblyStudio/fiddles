WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  env: {
    abort(_msg, _file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  },
}).then(result => {
  const { test1, test2 }  = result.instance.exports;

  const iters = 100000000;
  console.time('test1')
  for (let i = 0; i < iters; i++) {
    test1(i);
  }
  console.timeEnd('test1')

  console.time('test2')
  for (let i = 0; i < iters; i++) {
    test2(i);
  }
  console.timeEnd('test2')
}).catch(console.error);
