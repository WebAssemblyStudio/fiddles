WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  main: {
    sayHello() {
      console.log("Hello from WebAssembly!");
    }
  },
  env: {
    abort(_msg, _file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    },
    trace(_msg, count, a, b, c, d, e, f) {
      document.getElementById("container").textContent = a.toString();
    }
  },
}).then(result => {
  const exports = result.instance.exports;
  exports.run();
}).catch(console.error);
