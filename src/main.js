n = 32;

fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  instance = results.instance;
  
  document.getElementById("container").innerHTML += `<p>${measurePerf(() => instance.exports.fibonacci_reccursive(n), 10)}</p>`;
}).then(() => {
  document.getElementById("container").innerHTML += `<p>${measurePerf(() => fib(n), 10)}</p>`;
});

const fib = n => {
  if (n <= 0) {
    throw new Error('n must not be less or equal to zero');
  }
  switch(n) {
    case 1:
    case 2:
      return 1;
    case 3:
      return 2;
    default:
      return fib(n-1) + fib(n-2);
  }
}

const measurePerf = (f, n) => {
  let i = -1;
  const start = performance.now();
  while(++i < n) {
    f();
  }
  const end = performance.now();
  return `total: ${(end-start).toFixed(3)}ms, mean: ${((end-start)/n).toFixed(3)}ms`;
}