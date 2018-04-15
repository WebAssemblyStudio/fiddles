fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  module = results.module;
  instance = results.instance;
  var i32_in = new Uint32Array(instance.exports.memory.buffer, 0);
  for (var i = 0; i < 10; i++) {
    i32_in[i] = i;
  }
  let ptr = instance.exports.compute(0, 10);
  let i32_out = new Uint32Array(instance.exports.memory.buffer, ptr);
  let str = "ptr:"+ptr+" res:"+i32_out.slice(0, 10).join(",");
  document.getElementById("container").innerText = str;
});