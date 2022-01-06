async function getWasm() {
  const response = await fetch('../out/main.wasm');
  const arrayBuffer = await response.arrayBuffer();
  const prog = new Uint8Array(arrayBuffer);
  const results = await WebAssembly.instantiate(arrayBuffer);
  const instance = await results.instance;
  return instance;
}


getWasm().then((instance)=>{
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
});

