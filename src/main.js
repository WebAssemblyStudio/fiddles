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

  let image_in = [12, 25, 2, 255, 45, 63, 3, 255];
  const l = image_in.length

  let heap = new Uint8Array(memory.buffer, 0, l);
  console.log("#####")
  for (let i = 0; i < l; i++) {
      heap[i] = image_in[i];
  }

  let result = instance.exports.image_to_gray(0, 2, 1);
  console.log(result + "\n")

  for (let i = 0; i < l; i++) {
    console.log(heap[i]);
    console.log(heap[result + i]);
  }
}).catch(console.error);
