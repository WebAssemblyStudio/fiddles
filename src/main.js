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
  const a = new exports.Bruh()
  a.setV(385718)
  document.getElementById("container").textContent = "Result: " + exports.add(19, 23) + " " + a.getV();
}).catch(console.error);
