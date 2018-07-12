let memory = null;
const imports = {
  env: {
    getv(idx, dst) {
      (new Uint32Array(memory.buffer))[dst >> 2] = idx;
    }
  }
};

fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes, imports)).then(results => {
  instance = results.instance;
  memory = instance.exports.memory;
  document.getElementById("container").innerText = instance.exports.sum(10000);
}).catch(console.error);
