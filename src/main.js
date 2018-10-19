let pre = document.querySelector('pre');
fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(data => {
  function log(...args) {
    pre.textContent += [].join.call(args, ' ') + '\n';
  }
  let memory = new WebAssembly.Memory({initial: 1});
  let module = new WebAssembly.Module(data);
  let instance = new WebAssembly.Instance(module, {env: {memory, memoryBase: 0}});
  let squareEach = instance.exports.squareEach;
  const i32 = new Uint32Array(memory.buffer, 0, 15);
  for (let i = 0; i < 15; i++) {
    i32[i] = i;
  }
  log('before', i32);
  squareEach(15);
  log('after', i32);
}).catch(console.error);
