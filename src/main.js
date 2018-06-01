var memory = new WebAssembly.Memory({ initial: 1 });
var importObject = { imports: { memory: memory } };

WebAssembly.instantiateStreaming(fetch('../out/main.wasm'), importObject).then(results => {
  instance = results.instance;

  // create array of 100 elements; value from 0 to 99, i.e. [0..99]
  const data = Array.apply(null, {length: 100 }).map(Number.call, Number);
  const array = new Int32Array(memory.buffer);
  for (let i = 0; i < data.length; i++) {
    array[i] = data[i];
  }

  document.getElementById("container").innerText = instance.exports.sumAll(data.length);
});
