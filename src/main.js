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
    trace: console.log.bind(console)
  },
}).then(result => {
  const exports = result.instance.exports;

  document.getElementById("container").textContent = "Result: " + exports.mdeterm(1, 2, 3, 4);
}).catch(console.error);
