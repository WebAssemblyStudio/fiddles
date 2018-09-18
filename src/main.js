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

function runApp() {
  let js = measure(fib);
  let rust = measure(wasm_bindgen.fib);
  document.getElementById("container").innerText = `JS: ${js}\nRust: ${rust}`;
}

// Load and instantiate the wasm file, and we specify the source of the wasm
// file here. Once the returned promise is resolved we're ready to go and
// use our imports.
wasm_bindgen('../out/main_bg.wasm').then(runApp).catch(console.error);
