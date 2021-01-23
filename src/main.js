WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  env: {
    abort(_msg, _file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  },
}).then(result => {
  const exports = result.instance.exports;

  for (let i = 0; i < 500000; i++) {
    exports.isSpecialCharacter(i & 0x7F);
  }
  
  let t = performance.now();
  for (let i = 0; i < 50000000; i++) {
    exports.isSpecialCharacter(i & 0x7F);
  }
  t = performance.now() - t;
  console.log('isSpecialCharacter:', t + 'ms');

  for (let i = 0; i < 500000; i++) {
    exports.isSpecialCharacter2(i & 0x7F);
  }

  t = performance.now();
  for (let i = 0; i < 50000000; i++) {
    exports.isSpecialCharacter2(i & 0x7F);
  }
  t = performance.now() - t;
  console.log('isSpecialCharacter2:', t + 'ms');

}).catch(console.error);
