WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  env: {
    abort(_msg, _file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  },
}).then(result => {
  const exports = result.instance.exports;

  console.time('bench1');
  for (let i = 0; i < 1000; i++) {
    exports.bench1(200);
  }
  console.timeEnd('bench1');

  console.time('bench2');
  for (let i = 0; i < 1000; i++) {
    exports.bench2(200);
  }
  console.timeEnd('bench2');
}).catch(console.error);
