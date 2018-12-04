WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  main: {
    log_vec(x, y) {
      console.log(x, y);
    }
  },
  env: {
    abort(msg, file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  },
}).then(result => {
  const exports = result.instance.exports;
  document.getElementById("container").textContent = "Result: " + exports.add();
}).catch(console.error);
