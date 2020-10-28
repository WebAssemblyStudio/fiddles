fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  const { test_opt, test_orig } = results.instance.exports;
  console.log(test_orig(), test_opt());
}).catch(console.error);

