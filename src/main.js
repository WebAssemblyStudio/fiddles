fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  const exports = results.instance.exports;

  console.time('t');
  const res = exports.fib(38);
  console.timeEnd('t');
  console.log('res: ' + res);
}).catch(console.error);
