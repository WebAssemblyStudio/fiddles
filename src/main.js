fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  instance = results.instance;
  const buf = instance.exports.memory.buffer;
  const a = new Float64Array(buf,8,3)
  const b = new Float64Array(buf,8,3);
  a.set([ 6, 2, 3 ]);
  b.set([ 3, 2, 3 ]);
  document.getElementById("container").textContent = instance.exports.subtractArrays(a.byteOffset,b.byteOffset);
}).catch(console.error);
