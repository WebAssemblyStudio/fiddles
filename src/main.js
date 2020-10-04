WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  main: {
    sayHello() {
      console.log("Hello from WebAssembly!");
    }
  },
  env: {
    abort(_msg, _file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  },
}).then(result => {
  const exports = result.instance.exports;

  exports.sum1(100000000);
  exports.sum1(100000000);
  exports.sum1(100000000);

  let t;
  t = performance.now();
  exports.sum1(1000000000);
  t = performance.now() - t;
  console.log('sum1: ' + t + ' ms');

  exports.sum2(100000000);
  exports.sum2(100000000);
  exports.sum2(100000000);

  t = performance.now();
  exports.sum2(1000000000);
  t = performance.now() - t;
  console.log('sum2: ' + t + ' ms');
}).catch(console.error);
