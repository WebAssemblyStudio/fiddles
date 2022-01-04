fetch('../out/main.wasm').then(response =>
response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  instance = results.instance;

const func = new Float64Array(
  instance.exports.memory.buffer,
  instance.exports.funcptr(),
  1024
);

const stack = new Float64Array(
  instance.exports.memory.buffer,
  instance.exports.stackptr(),
  1024
);

const reg = new Float64Array(
  instance.exports.memory.buffer,
  instance.exports.regptr(),
  1024
);

const prog = new Uint32Array(
  instance.exports.memory.buffer,
  instance.exports.progptr(),
  1024
);

instance.exports.init();
instance.exports.push(5);
instance.exports.push(4);
instance.exports.push(3);
instance.exports.push(2);
prog[0]=3;
prog[1]=1;
instance.exports.ex(1);


document.getElementById("container").textContent = stack.join(' | ');
}).catch(console.error);
