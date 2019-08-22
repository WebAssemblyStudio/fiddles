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
  document.getElementById("container1").textContent = "Result_1: " + exports.add(19, 23);
  document.getElementById("container2").textContent = "Result_2: " + exports.apply(exports.foo());
}).catch(console.error);
