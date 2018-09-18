const fib = n => {
  let a = 1;
  let b = 1;
  for (let i = 0; i < n - 1; i++) {
    const c = a;
    a = b;
    b = c + b;
  }
  return a;
}

const measure = f => {
  const start = performance.now();
  for (let i = 0; i < 1000000; i++) {
    f(47);
  }
  return performance.now() - start;
}

fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(({ instance }) => {
  let js = measure(fib);
  let rust = measure(instance.exports.fib);
  document.getElementById("container").innerText = `JS: ${js}\nRust: ${rust}`;
}).catch(console.error);
