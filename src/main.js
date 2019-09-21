WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  env: {
    abort(_msg, _file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  },
}).then(result => {
  const exports = result.instance.exports;

  console.time('AS sin time');
  const acc = exports.testSin();
  console.timeEnd('AS sin time');

  console.log('AS sin res: '+ acc);

  console.time('JS sin time');
  let acc2 = 0;
  for (let i = 0; i < 100000000; i++) {
    acc2 += Math.sin(i * (0.125 / Math.PI));
  }
  console.timeEnd('JS sin time');
  console.log('JS sin res: ' + acc2);

}).catch(console.error);
