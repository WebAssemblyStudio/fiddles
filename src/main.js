WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  env: {
    abort(msg, file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  },
}).then(result => {
  const exports = result.instance.exports;
  
  console.time('sign1');
  for (let i = -10000000; i < 10000000; i++) {
    exports.sign1(i);
  }
  console.timeEnd('sign1');

  console.time('sign2');
  for (let i = -10000000; i < 10000000; i++) {
    exports.sign2(i);
  }
  console.timeEnd('sign2');
}).catch(console.error);
