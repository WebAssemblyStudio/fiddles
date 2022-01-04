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
const fn = {
  div: 0,
  mul: 1,
  sub: 2,
  add: 3,
  powyx: 4,
  ln: 5,
  swap: 6,
  getx: 7
}
instance.exports.push(123.456);
instance.exports.push(789.654);

prog[0]=fn.add;
prog[1]=fn.ln;
instance.exports.ex(1);


document.getElementById("container").textContent = instance.exports.getx();
}).catch(console.error);
