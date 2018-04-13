fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  module = results.module;
  instance = results.instance;
  let i32 = new Uint32Array(instance.exports.memory.buffer, 8);
  for (var i = 0; i < 10; i++) {
    i32[i] = i;
  }
  let size = instance.exports.compute(8, 10);
  let str = i32.slice(0, size).join(",");
  document.getElementById("container").innerText = str;
});