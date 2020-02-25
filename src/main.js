const heap = new Uint8Array(memory.buffer);

for (let i = 0; i < heap.length; i++)
{
  heap[i] = Math.floor(Math.random() * 256);
}

console.log(`Calculate the average of an array with ${heap.length} elements`);

WebAssembly.instantiateStreaming(fetch('../out/main.wasm')).then(obj => {

  document.getElementById("wasmExec").addEventListener('click', ev => {
    const t0 = performance.now();
    const result = obj.instance.exports.avgRoot(0,heap.length);
    const t1 = performance.now();

    document.getElementById("webAsmContainer").textContent = `the result ${result} was calculated in ${t1 - t0} ms`;
  });

  document.getElementById("javascriptExec").addEventListener('click', ev => {
    const t0 = performance.now();
    
    let avg = heap[0];
    for (let i = 1; i < heap.length; i++) {
      avg += heap[i];
    }

    avg /= heap.length;
    
    const t1 = performance.now();

    document.getElementById("javascriptContainer").textContent = `the result ${avg} was calculated in ${t1 - t0} ms`;
  });

}).catch(console.error);
