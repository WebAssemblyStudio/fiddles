WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  env: {
    abort(msg, file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  },
}).then(result => {
  const exports = result.instance.exports;
  let res;
  console.time('t1');
  res = exports.test1(10);
  console.timeEnd('t1');
  console.log('t1 = ' + res);

  console.time('t2');
  res = exports.test2(10);
  console.timeEnd('t2');
  console.log('t2 = ' + res);

  console.time('t3');
  res = exports.test3(10);
  console.timeEnd('t3');
  console.log('t3 = ' + res);
}).catch(console.error);
