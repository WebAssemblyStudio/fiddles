function calcula() {
  var a=document.getElementById("va").value;
  var b=document.getElementById("vb").value;
  var c=document.getElementById("vc").value;

fetch('../out/main.wasm')
.then(response => response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)
).then(results => {
  instance = results.instance;
  document.getElementById("container").textContent = instance.exports.x1(a,b,c);
}).catch(console.error);

fetch('../out/main.wasm')
.then(response => response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)
).then(results => {
  instance = results.instance;
  document.getElementById("container2").textContent = instance.exports.x2(a,b,c);
}).catch(console.error);
}