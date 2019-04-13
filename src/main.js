WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  env: {
    abort(msg, file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  },
}).then(result => {
  const exports = result.instance.exports;
  exports.init();

  console.time('wasm');
  exports.test();
  console.timeEnd('wasm');

  // let arr = Array.from({ length: 1000000 }, () => (Math.random() * 1000000) | 0);
  // let arr = Array.from({ length: 1000000 }, (_,i) => i | 0);
  let arr = Array.from({ length: 1000000 }, (_,i) => 1000000 - i - 1);

  console.time('js');
  arr.sort((a, b) => a - b);
  console.timeEnd('js');
}).catch(console.error);
