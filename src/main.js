fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  instance = results.instance;
  const data = new Float32Array([1, 2, 3, 4, 9]);

  const nDataBytes = data.length * data.BYTES_PER_ELEMENT;

  const linearMemory = instance.exports.memory;

  const dataHeap = new Uint8Array(linearMemory.buffer, 0, nDataBytes);
  dataHeap.set(new Uint8Array(data.buffer));
  const value = instance.exports.sum_of_array(0,nDataBytes);
}).catch(console.error);


