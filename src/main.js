WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  env: {
    abort(_msg, _file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  },
}).then(result => {
  const exports = result.instance.exports;

  console.time('t1')
  for (let i = 0; i < 100000000; i++)
     exports.test1(i);
  console.timeEnd('t1')

  console.time('t2')
  for (let i = 0; i < 100000000; i++)
     exports.test2(i);
  console.timeEnd('t2')
}).catch(console.error);
