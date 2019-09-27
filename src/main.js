WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  main: {
    sayHello() {
      console.log("Hello from WebAssembly!");
    }
  },
  env: {
    abort(_msg, _file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  },
}).then(result => {
  const exports = result.instance.exports;
  // document.getElementById("container").textContent = "Result: " + exports.add(19, 23);
  document.getElementById("container").textContent = "test1: " + exports.test1(10, 20, 30);
}).catch(console.error);
