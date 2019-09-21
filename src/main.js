
function testSinJS() {
  let acc = 0;
  for (let i = 0; i < 10000; i++) {
    acc += Math.sin(i * (0.125 / Math.PI));
  }
  return acc;
}

WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  env: {
    abort(_msg, _file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  },
}).then(result => {
  const { testSin: testSinAS, testSinf32: testSinf32AS } = result.instance.exports;

  for (let i = 0; i < 1000;i++)
  testSinAS();

  console.time('AS sin time');
  const acc = testSinAS();
  console.timeEnd('AS sin time');

  console.log('AS sin res: '+ acc);

  for (let i = 0; i < 1000;i++)
  testSinf32AS();

  console.time('AS sin f32 time');
  const acc1 = testSinf32AS();
  console.timeEnd('AS sin f32 time');

  console.log('AS sin f32 res: ' + acc1);

  for (let i = 0; i < 1000;i++)
  testSinJS();

  console.time('JS sin time');
  const acc2 = testSinJS();
  console.timeEnd('JS sin time');
  console.log('JS sin res: ' + acc2);

}).catch(console.error);
