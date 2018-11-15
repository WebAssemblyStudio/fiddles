instantiateStreaming(fetch("../out/main.wasm"), {
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
  console.log(result)
  document.getElementById("container").textContent = "Result: " + result.makeContract(123);
  console.log(result.memory);
}).catch(console.error);
