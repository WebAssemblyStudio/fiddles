function fib(n){
  if(n<=2){
    return 1;
  }
  return fib(n-1) + fib(n-2);
}


fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  instance = results.instance;
  console.time('JS Fib')
  document.getElementById("container").textContent = fib(24);
  console.timeEnd('JS Fib')
  console.time('WASM Fib')
  document.getElementById("container").textContent = instance.exports.fib(24);
  console.timeEnd('WASM Fib')
}).catch(console.error);
