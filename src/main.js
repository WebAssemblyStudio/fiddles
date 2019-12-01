function fibonacci(n) {
    return n < 1 ? 0
        : n <= 2 ? 1
        : fibonacci(n - 1) + fibonacci(n - 2);
  }

WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  env: {
    abort(_msg, _file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  },
}).then(result => {
  const wasm = result.instance.exports;

  console.time('TS');
  console.log('TS =', fibonacci(45));
  console.timeEnd('TS');

  console.time('AS');
  console.log('AS =', wasm.fibonacci(45));
  console.timeEnd('AS');
}).catch(console.error);
