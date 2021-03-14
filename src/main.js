const memory = new WebAssembly.Memory({ initial: 256 })

// fill memory.buffer
const memoryBytes = new Uint32Array(memory.buffer);
for(let i = 0; i < memoryBytes.length; i++)
  memoryBytes[i] = Math.floor((Math.random() * 1000) + 1);

function log(arrayOffset) {
  const offset = memoryBytes[arrayOffset + 2];
  const length = memoryBytes[arrayOffset];
  const bytes = new Uint32Array(memory.buffer, offset, length);
  const debugBytes = "";
  for(let i=0; i < bytes.byteLength; i++) {
      debugBytes.concat(bytes[i].toString());
      debugBytes.concat(",");
  }
  console.log('Processing packet [' + bytes[1] + '] ' + debugBytes);
}

const framePointer = new WebAssembly.Global({ value: "i32", mutable: true }, 0);
const importObj = { imports: { log }, js: { global: framePointer , memory } };

fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes, importObj)).then(results => {
  instance = results.instance;
  document.getElementById("container").textContent = instance.exports.add(2, 2);
}).catch(console.error);

