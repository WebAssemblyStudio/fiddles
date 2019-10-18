fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => {
  const imports = {
    f: {
      x: new WebAssembly.Global({
      value: 'i32',
        mutable: true
      }, 10)
    }
  };
  return WebAssembly.instantiate(bytes, imports);
}).then(results => {
  const instance = results.instance;
  const x = instance.exports.add(1, 1);
  container.textContent = x;
}).catch(console.error);

