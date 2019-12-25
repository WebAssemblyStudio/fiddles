/*const memory = new WebAssembly.Memory({
    initial: 256,
    maximum: 256
});

const heap = new Uint8Array(memory.buffer);

fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  instance = results.instance;
  alert(reverse([1,2,3])[0]);
  alert(reverse([1,2,3])[1]);
  alert(reverse([1,2,3])[2]);
}).catch(console.error);

function reverse(arr) {
    for (let i = 0; i < arr.length; ++i) {
        heap[i] = arr[i];
    }
    instance.exports.reverse(heap, arr.length);

    const result = [];
    for (let i = 0; i < arr.length; ++i) {
        result.push(heap[i]);
    }
    return result;
}*/

const fs = require('fs');

const memory = new WebAssembly.Memory({
    initial: 256,
    maximum: 256
});
const heap = new Uint8Array(memory.buffer);
const imports = {
    env: {
        memory: memory
    }
};

const wasmModule = new WebAssembly.Module(fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
));
const wasmInstance = new WebAssembly.Instance(wasmModule, imports);

function reverse(arr) {
    for (let i = 0; i < arr.length; ++i) {
        heap[i] = arr[i];
    }
    wasmInstance.exports._reverse(0, arr.length);

    const result = [];
    for (let i = 0; i < arr.length; ++i) {
        result.push(heap[i]);
    }
    return result;
}

const numbers = [14, 3, 77];
alert(numbers, 'becomes', reverse(numbers));
