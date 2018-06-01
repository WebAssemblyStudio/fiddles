var memory = new WebAssembly.Memory({ initial: 1 });
var importObject = { imports: { memory: memory } };

WebAssembly.instantiateStreaming(fetch('../out/main.wasm'), importObject).then(results => {
  instance = results.instance;

  const data = [1, 2, 3];
  const array = new Int8Array(memory.buffer);
  for (let i = 0; i < data.length; i++) {
    array[i] = data[i];
  }

  document.getElementById("container").innerText = instance.exports.sumAll(data.length);
});
