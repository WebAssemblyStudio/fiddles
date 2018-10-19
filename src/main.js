let pre = document.querySelector('pre');
fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(data => {
  function log(...args) {
    pre.textContent += [].join.call(args, ' ') + '\n';
  }
  let module = new WebAssembly.Module(data);
  let instance = new WebAssembly.Instance(module);
  let squareEach = instance.exports.squareEach;
  let memory = instance.exports.memory;
 
  const i32 = new Uint32Array(memory.buffer, 0, 15);
  for (let i = 0; i < 15; i++) {
    i32[i] = i;
  }
  log('before', i32);
  squareEach(0, 15);
  log('after1', i32);
  squareEach(5 * i32.BYTES_PER_ELEMENT, 3);
  log('after2', i32);
}).catch(console.error);
