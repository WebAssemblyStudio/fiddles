fetch('../out/fib_loop.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  instance = results.instance;
  document.getElementById("container").textContent = instance.exports.fibonacci(12, 0);
  var mem = new Uint8Array(instance.exports.mem.buffer);
  var memDOM = document.getElementById("mem");
  for (var i = 0; i < mem.length; i++) {
    var child = document.createElement("li");
    var text = document.createTextNode(mem[i]);
    child.appendChild(text);
    memDOM.appendChild(child);
  }

}).catch(console.error);

