WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  env: {
    abort(msg, file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  },
}).then(result => {
  const exports = result.instance.exports;
  console.time('fill');
  for (let i = 0; i < 100000; i++) {
    exports.fill();
  }
  console.timeEnd('fill');

  console.time('loop');
  for (let i = 0; i < 100000; i++) {
    exports.loop();
  }
  console.timeEnd('loop');
}).catch(console.error);
