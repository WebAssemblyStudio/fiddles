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
  let fn = function(x) {
    return x + 1;
  };
  document.getElementById("container").textContent = "Result: " + exports.add(fn, 19, 23);
}).catch(console.error);
