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
  const mem = new Uint32Array(exports.memory.buffer);
  document.getElementById("container").textContent = "Result: " + exports.add(19, 23);

  // const name = result.instance.newString("James");
  const greeting = exports.getGreeting("James");
  console.log(greeting);
}).catch(console.error);
