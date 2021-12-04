fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  instance = results.instance;

  // const { memory, sum } = instance.exports;
  // const array = new Int32Array(memory.buffer, 0, 5);

  // array.set([1, 2, 3]);

  // const result = sum(array.byteOffset, array.length);

  const { memory, fill } = instance.exports;
  const array = new Int32Array(memory.buffer, 0, 5);
  fill(array.byteOffset, array.length, 2112);

  document.getElementById("container").textContent = array.toString();
}).catch(console.error);
