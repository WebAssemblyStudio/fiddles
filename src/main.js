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

  let arr = Array.from({ length: 1000000 }, () => (Math.random() * 1000000) | 0);

  console.time('sort');
  arr.sort((a, b) => a - b);
  console.timeEnd('sort');

}).catch(console.error);
