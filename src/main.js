fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  instance = results.instance;
  var data = new Float32Array([1, 2, 3, 4, 5]);

// Get data byte size, allocate memory on Emscripten heap, and get pointer
var nDataBytes = data.length * data.BYTES_PER_ELEMENT;

const linearMemory = instance.exports.memory;

var dataHeap = new Uint8Array(linearMemory.buffer, 0, nDataBytes);
dataHeap.set(new Uint8Array(data.buffer));
const value = instance.exports.display_array(0,nDataBytes);
console.log(value);
}).catch(console.error);
