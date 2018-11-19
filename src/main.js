WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  main: {
    sayHello() {
      console.log("Hello from WebAssembly!");
    }
  },
  env: {
    abort(msg, file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  },
}).then(result => {
  const exports = result.instance.exports;
  document.getElementById("container").textContent = "Result: " + exports.add(19, 23);
  document.getElementById("container").textContent += "Result: " + exports.compare("key1", "key2");
  document.getElementById("container").textContent += "Result: " + exports.compare("key1", "keyw");
  document.getElementById("container").textContent += "Result: " + exports.compare("a", "a");
  document.getElementById("container").textContent += "Result: " + exports.compare("kk", "ab");


}).catch(console.error);
