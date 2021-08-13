const importObject = {
  imports: {
    random: Math.random,
  },
};

fetch('../out/main.wasm')
  .then(response => response.arrayBuffer())
  .then(bytes => WebAssembly.instantiate(bytes, importObject))
  .then(results => {
    const instance = results.instance;
    console.log(instance.exports.throwNeedle(100000000)*4);
  })
  .catch(console.error);

