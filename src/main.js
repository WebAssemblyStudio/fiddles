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

  let crc = 12334n;
  let t = performance.now();
  for (let i = 0n; i < 10000000n; i++) {
    crc = exports.crc64_1(crc, i);
  }
  t = performance.now() - t;
  console.log('crc64_1: ' + t + ' ms');

  crc = 12334n;
  t = performance.now();
  for (let i = 0n; i < 10000000n; i++) {
    crc = exports.crc64_2(crc, i);
  }
  t = performance.now() - t;
  console.log('crc64_2: ' + t + ' ms');

}).catch(console.error);
