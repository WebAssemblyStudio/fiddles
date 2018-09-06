WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  env: {
    abort(msg, file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  }
}).then(result => {
  const exports = result.instance.exports;
  document.getElementById("container").innerText = "Result: " + (exports.test() ? "true" : "false");
}).catch(console.error);
