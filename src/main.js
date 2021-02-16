const memory = new WebAssembly.Memory({
    initial: 256,
});

const imports = {
    env: {
        memoryBase: 0,
        memory: memory,
        tableBase: 0,
        table: new WebAssembly.Table({initial: 0, element: 'anyfunc'})
    }
};


fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes, imports)).then(results => {
  instance = results.instance;

  const exports = instance.exports

    // Get the function out of the exports.
  const { bufferSum, memory } = results.instance.exports

  let heap = new Uint8Array(memory.buffer, 0, 5);

  let buffer_in = [1, 2, 5, 12, 25]

  for (let i = 0; i < buffer_in.length; i++) {
      heap[i] = buffer_in[i];
  }

  let result = instance.exports.bufferSum(0, buffer_in.length);
  console.log(result)
}).catch(console.error);
