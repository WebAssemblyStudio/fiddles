WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  env: {
    abort(_msg, _file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  },
}).then(result => {
  const exports = result.instance.exports;
  const I = [1, 6, 8];
  const J = [3, 3, 5];
  console.time('two tables');
  for (let i = 0; i < 1000; i++) {
    for (let j = 0; j < 1000; j++) {
      exports.virtual1(j % J[i % 3], I[i % 3]);
    }
  }
  console.timeEnd('two tables');

  console.time('one table');
  for (let i = 0; i < 1000; i++) {
    for (let j = 0; j < 1000; j++) {
      exports.virtual2(j % J[i % 3], I[i % 3]);
    }
  }
  console.timeEnd('one table');
}).catch(console.error);
