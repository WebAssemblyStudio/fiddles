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
  logx: 5,
  expx: 6,
  swap: 7,
  getx: 8
}

instance.exports.push(123.456);
instance.exports.push(321.654);
instance.exports.push(111.222);
prog[0]=fn.sub;
prog[1]=fn.logx;
prog[2]=fn.swap;
prog[3]=fn.logx;
prog[4]=fn.add;
prog[5]=fn.expx;
instance.exports.ex(5);


document.getElementById("container").textContent = instance.exports.getx();
}).catch(console.error);
