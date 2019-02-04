
function fib(x) {
  if (x <= 1) return x;
  return fib(x - 1) + fib(x - 2);
}

WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  env: {
    abort(msg, file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  },
}).then(result => {
  const exports = result.instance.exports;

  const wasmStart = performance.now();
  const wasmResult = exports.fib(40);
  const wasmTime = performance.now() - wasmStart;
  
  const jsStart = performance.now();
  const jsResult = fib(40);
  const jsTime = performance.now() - jsStart;

  document.getElementById('container').textContent = `
    WebAssembly result: ${wasmResult}, time: ${wasmTime}ms;
    JS result: ${jsResult}, time: ${jsTime}ms
  `;
}).catch(console.error);
