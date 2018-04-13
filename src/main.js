fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  module = results.module;
  instance = results.instance;
  var i32 = new Uint32Array(instance.exports.memory.buffer);
  for (var i = 0; i < 10; i++) {
    i32[i] = i;
  }
  let size = instance.exports.compute(0, 10);
  let str = i32.slice(1, size).join(",");
  document.getElementById("container").innerText = str;
});