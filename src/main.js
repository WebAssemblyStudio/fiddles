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
instance.exports.push(123.456);
instance.exports.push(456.123);
instance.exports.ex(2);


document.getElementById("container").textContent = stack;
}).catch(console.error);
