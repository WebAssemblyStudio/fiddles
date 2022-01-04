fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  instance = results.instance;
const func = new Uint32Array(
  instance.exports.memory.buffer,
  instance.exports.funcptr(),
  1024
);

const stack = new Float64Array(
  instance.exports.memory.buffer,
  instance.exports.stackptr(),
  1024
);
  instance.exports.main();
  instance.exports.push(123.456);
  instance.exports.push(234.458);
  //instance.exports.ex();
  document.getElementById("container").textContent = func;
}).catch(console.error);
