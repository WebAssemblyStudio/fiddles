WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  env: {
    abort(_msg, _file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  },
}).then(result => {
  const exports = result.instance.exports;
  let acc = 0;

  console.time('abs1');
  for (let i = -10000000; i < 10000000; i++) {
    acc += exports.abs1(i);
  }
  console.timeEnd('abs1');

  acc = 0;
  console.time('abs2');
  for (let i = -10000000; i < 10000000; i++) {
    acc += exports.abs2(i);
  }
  console.timeEnd('abs2');

}).catch(console.error);
