let pre = document.querySelector('pre');
fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(data => {

  function log(...args) {
    pre.textContent += [].join.call(args, ' ') + '\n';
  }

  let memory = new WebAssembly.Memory({initial: 1});
  let module = new WebAssembly.Module(data);
  let instance = new WebAssembly.Instance(module, {env: {memory}});
  let best = instance.exports.best;
  
  const i32 = new Uint32Array(memory.buffer, 0, 10);
  a = new Uint32Array([10, 10, 10, 10, 10]);
  b = new Uint32Array([20, 20, 20, 20, 20]);
  i32.set(a, 0);
  i32.set(b, a.length);
  log('before', i32);
  best(0, a.length, b.length);
  log('after', i32);
}).catch(console.error);
