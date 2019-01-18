WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  main: {},
  env: {
    abort(msg, file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  },
}).then(result => {
  const fibonacci = result.instance.exports.fibonacci;
  document.getElementById("container").textContent = "Result: " + fibonacci(45);
}).catch(console.error);
