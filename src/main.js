fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  instance = results.instance;
  let h = new Uint8Array(instance.exports.memory.buffer);
  document.getElementById("container").textContent = utf8ToString(h, instance.exports.main());
}).catch(console.error);

function utf8ToString(h, p) {
  let s = "";
  for (i = p; h[i]; i++) {
    s += String.fromCharCode(h[i]);
  }
  return s;
}