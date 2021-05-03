WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  env: {
    abort(_msg, _file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  },
}).then(result => {
  const exports = result.instance.exports;

  const N = 1_000_000;

  let t = performance.now();

  exports.test(N);

  t = performance.now() - t;

  document.getElementById("container").textContent = "time (new): " + t + " ms";
}).catch(console.error);
