WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  env: {
    abort(_msg, _file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  },
}).then(result => {
  const exports = result.instance.exports;
  const K = [3, 3, 5];
  console.time('two tables');
  for (let i = 0; i < 1000; i++) {
    for (let j = 0; j < 1000; j++) {
      let k = i % 3;
      exports.virtual1(k, j % J[k]);
    }
  }
  console.timeEnd('two tables');

  console.time('one table');
  for (let i = 0; i < 1000; i++) {
    for (let j = 0; j < 1000; j++) {
    let k = i % 3;
     exports.virtual2(k, j % J[k]);
    }
  }
  console.timeEnd('one table');
}).catch(console.error);
