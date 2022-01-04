fetch('../out/main.wasm').then(response =>
response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  instance = results.instance;
  const wasm = instance.exports;

const func = new Float64Array(
  wasm.memory.buffer,
  wasm.funcptr(),
  1024
);

const stack = new Float64Array(
  wasm.memory.buffer,
  wasm.stackptr(),
  1024
);

const reg = new Float64Array(
  wasm.memory.buffer,
  wasm.regptr(),
  1024
);

const prog = new Uint32Array(
  wasm.memory.buffer,
  wasm.progptr(),
  1024
);

wasm.init();
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

wasm.push(123.456);
wasm.push(321.654);
wasm.push(111.222);
prog[0]=fn.sub;
prog[1]=fn.logx;
prog[2]=fn.swap;
prog[3]=fn.logx;
prog[4]=fn.add;
prog[5]=fn.expx;
wasm.ex(5);


document.getElementById("container").textContent = wasm.getx();
}).catch(console.error);
