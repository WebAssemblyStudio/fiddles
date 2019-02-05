function test(name, block) {
  var start = performance.now();
  var result = block();
  var end = performance.now();
  console.log(`name ${(end - start).toFixed(1)} ${result}`);
}

fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  instance = results.instance;
  test('add', () => instance.exports.add(1,1));
  test('facCall', () => instance.exports.facCall(1000));
}).catch(console.error);

