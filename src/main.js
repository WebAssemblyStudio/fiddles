const memory = new WebAssembly.Memory({
    initial: 1,
    maximum: 1,
});

const heap = new Uint8Array(memory.buffer);

for (let i = 0; i < heap.length; i++)
{
  heap[i] = Math.floor(Math.random() * 256);
}

const importObject = {
    env: {
        memory: memory,
    },
};

console.log(heap[0]);

WebAssembly.instantiateStreaming(fetch('../out/main.wasm'), importObject).then(obj => {

  document.getElementById("wasmExec").addEventListener('click', ev => {
    const t0 = performance.now();
    const result = obj.instance.exports.avgRoot(0,heap.length);
    const t1 = performance.now();

    document.getElementById("webAsmContainer").textContent = `the result ${result} was calculated in ${t1 - t0} ms`;
  });

  document.getElementById("javascriptExec").addEventListener('click', ev => {
    const t0 = performance.now();
    
    let avg = 0;
    for (let i = 0; i < heap.length; i++) {
      avg = (avg + heap[i]) / 2;
    }
    
    const t1 = performance.now();

    document.getElementById("javascriptContainer").textContent = `the result ${avg} was calculated in ${t1 - t0} ms`;
  });

}).catch(console.error);
