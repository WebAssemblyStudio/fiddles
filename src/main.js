const memory = new WebAssembly.Memory({
    initial: 1,
    maximum: 1,
});

const heap = new Uint8Array(memory.buffer);

let a = 30;
let b = 40;

//save a to memory
heap[10] = a;

//save b to memory
heap[11] = 0;
heap[12] = b;


WebAssembly.instantiateStreaming(fetch('../out/main.wasm'), importObject).then(obj => {

  document.getElementById("wasmExec").addEventListener('click', ev => {
    const t0 = performance.now();
    const result = obj.instance.exports.addStruct(10);
    const t1 = performance.now();

    document.getElementById("webAsmContainer").textContent = `the result is ${result}`;
  });


}).catch(console.error);
