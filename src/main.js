const memory = new WebAssembly.Memory({
    initial: 1,
    maximum: 1,
});

const heap = new Uint8Array(memory.buffer);

let a = 30;
let b = 258; //0x0102

//save a to memory
heap[10] = a;
//this is a padding byte
heap[11] = 0x0;

//save b to memory
heap[13] = b >>> 8; //0x01
heap[12] = 0xFF & b; //0x02

const importObject = {
    env: {
        memory: memory,
    },
};


WebAssembly.instantiateStreaming(fetch('../out/main.wasm'), importObject).then(obj => {

  document.getElementById("wasmExec").addEventListener('click', ev => {
    const t0 = performance.now();
    const result = obj.instance.exports.addStruct(10);
    const t1 = performance.now();

    document.getElementById("webAsmContainer").textContent = `the result is ${result}`;
  });


}).catch(console.error);
