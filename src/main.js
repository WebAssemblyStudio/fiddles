WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  main: {
    init() {
      console.log("WebAssembly is working!");
    }
  },
  env: {
    abort(msg, file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  },
}).then(result => {
  const exports = result.instance.exports;
  document.getElementById("container").textContent = exports.random(1,2);
  
}).catch(console.error);
