WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  env: {
    abort(_msg, _file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  },
}).then(result => {
  const exports = result.instance.exports;

  let res = 0;
  console.time('fib (AS)');
  for (let i = 0; i < 1000; i++) {
    res += exports.fib(20);
  }
  console.timeEnd('fib (AS)');
  console.log('fib AS res: ' + res);

  WebAssembly.instantiateStreaming(fetch("../out/fib_c.wasm"), {
    env: {
      abort(_msg, _file, line, column) {
        console.error("abort called at main.ts:" + line + ":" + column);
      }
    },
  }).then(result => {
    const exports = result.instance.exports;

    let res = 0;
    console.time('fib (C)');
    for (let i = 0; i < 1000; i++) {
      res += exports.fib(20);
    }
    console.timeEnd('fib (C)');
    console.log('fib C res: ' + res);

  }).catch(console.error);
}).catch(console.error);