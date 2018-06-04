function jsFib(n) {
  let fiba = 0, fibb = 1, current = 0;
  for(let i = 0; i <= n; ++i) {
    current = fiba + fibb;
    fiba = fibb;
    fibb = current;
  }
  return current;
}

fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  let instance = results.instance;
  let start = Date.now();
  instance.exports.wasmFib(9999999999)
  document.getElementById("wasm-fib-time").innerText = Date.now() - start;
});

let jsStart = Date.now();
jsFib(9999999999)
document.getElementById("js-fib-time").innerText = Date.now() - jsStart;