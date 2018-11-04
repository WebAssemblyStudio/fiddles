WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  env: {
    abort(msg, file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  },
}).then(result => {
  const exports = result.instance.exports;
  console.time('t');
  const res = exports.fib(38);
  console.timeEnd('t');
  console.log('res: ' + res);
}).catch(console.error);
