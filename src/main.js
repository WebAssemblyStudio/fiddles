fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  instance = results.instance;
  const test = instance.exports._Z4testb;
  console.log('test(true)', test(true));
  console.log('test(false)', test(false));
  console.log('test(2)', test(2));
  console.log('test(-1)', test(-1));
}).catch(console.error);
