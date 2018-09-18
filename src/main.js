const fib = n => {
  if (n == 0 || n == 1) {
    return 1;
  } else {
    return fib(n - 2) + fib(n - 1);
  }
}

const measure = f => {
  const start = performance.now();
  for (let i = 0; i < 1000; i++) {
    f(30);
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
