const memory = new WebAssembly.Memory({
    initial: 256,
});
let heap = new Uint8Array(memory.buffer);

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

  let buffer_in = new Uint8Array([1, 2, 5, 12, 25])

  for (let i = 0; i < buffer_in.length; i++) {
      heap[i] = buffer_in[i];
  }

  document.getElementById("container").textContent = instance.exports.bufferSum(0, buffer_in.length);
}).catch(console.error);
