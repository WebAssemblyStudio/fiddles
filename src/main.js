let memory;

function submit_rgb(ptr, len) {
  const array = new Uint8Array(memory.buffer).slice(ptr, ptr + len * 3);
  for (let i = 0; i < len; i++) {
    const r = array[i * 3 + 0];
    const g = array[i * 3 + 1];
    const b = array[i * 3 + 2];
    console.log(`color: r:${r} g:${g} b:${b}`);
  }

}

fetch('../out/main.wasm')
  .then(response => response.arrayBuffer())
  .then(bytes => WebAssembly.instantiate(bytes, { env: { submit_rgb }}))
  .then(results => {
    memory = results.instance.exports.memory;
    results.instance.exports.run()
  });
