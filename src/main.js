WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  env: {
    abort(_msg, _file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  },
}).then(result => {
  const exports = result.instance.exports;

  for (let i = 0; i < 4000000; i++) {
    exports._set(i, 100);
  }

  console.time('current')
  for (let i = 0; i < 4000000; i++) {
    exports._set(i, 100);
  }
  console.timeEnd('current')

  for (let i = 0; i < 4000000; i++) {
    exports._set2(i, 100);
  }

  console.time('next')
  for (let i = 0; i < 4000000; i++) {
    exports._set2(i, 100);
  }
  console.timeEnd('next')
}).catch(console.error);
