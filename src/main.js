WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  env: {
    abort(msg, file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  },
}).then(result => {
  const exports = result.instance.exports;
  console.time('t1');
  for (let i = 0; i < 1000000; i++)
    exports.reverse(i);
  console.timeEnd('t1');

  console.time('t2');
  for (let i = 0; i < 1000000; i++)
    exports.reverse_knuth(i);
  console.timeEnd('t2');
}).catch(console.error);
