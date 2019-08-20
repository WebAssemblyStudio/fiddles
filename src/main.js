WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  main: {
    log(v) {
      console.log(v);
    }
  },
  env: {
    abort(_msg, _file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  },
}).then(result => {
  const exports = result.instance.exports;
  
  let acc1 = 0;
  console.time('t1');
  for (let i = 0.0; i < 1e80; i += 1e80 / 100000000) {
    acc1 += exports.toInt32_1(i);
  }
  console.timeEnd('t1');

  let acc2 = 0;
  console.time('t2');
  for (let i = 0.0; i < 1e80; i += 1e80 / 100000000) {
    acc2 += exports.toInt32_2(i);
  }
  console.timeEnd('t2');

}).catch(console.error);
