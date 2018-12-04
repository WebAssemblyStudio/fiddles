WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  main: {
    log_vec(...args) {
      console.log(...args);
    }
  },
  env: {
    abort(msg, file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  },
}).then(result => {
  const exports = result.instance.exports;
  console.log(exports);
  document.getElementById("container").textContent = "Result: " + exports.add();
}).catch(console.error);
