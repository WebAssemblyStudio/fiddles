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
  console.log(exports.getSharedArrayPtr())
  var sharedArray = new Uint8Array(exports.memory.buffer, // WASM's memory
                                   exports.getSharedArrayPtr(), // myArray's pointer
                                   100 // The array's length
  );

  let buffer_in = new Uint8Array([1, 2, 5, 12, 25])

  for (let i = 0; i < buffer_in.length; i++) {
      sharedArray[i] = buffer_in[i];
  }
  // heap.set(buffer_in);
  // instance.exports.bufferOffset(0, buffer_in.length)
  // document.getElementById("container").textContent = "Bang " + heap[buffer_in.length + 1];
  document.getElementById("container").textContent = instance.exports.bufferSum(0, buffer_in.length);
}).catch(console.error);
