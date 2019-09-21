
function testSinJS() {
  let acc = 0;
  for (let i = 0; i < 100000000; i++) {
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
  const { testSin: testSinAS } = result.instance.exports;

  testSinAS();
  testSinAS();

  console.time('AS sin time');
  const acc = testSinAS();
  console.timeEnd('AS sin time');

  console.log('AS sin res: '+ acc);

  testSinJS();
  testSinJS();

  console.time('JS sin time');
  const acc2 = testSinJS();
  console.timeEnd('JS sin time');
  console.log('JS sin res: ' + acc2);

}).catch(console.error);
