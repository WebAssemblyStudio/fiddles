
function fibonacci(n) {
  if (n == 1 || n == 2) return 1;
  return fibonacci(n - 1) + fibonacci(n - 2);
}
console.time('js');
fibonacci(30);
console.timeEnd('js');

fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  console.time('rust')
  instance = results.instance;
  document.getElementById("container").textContent = instance.exports.fibonacci(30);
  console.timeEnd('rust')
}).catch(console.error);
