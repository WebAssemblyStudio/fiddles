WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  env: {
    sayHello() {
      console.log("Hello from WebAssembly!");
    },
    abort(msg, file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  },
  main: {
    logi(value) { console.log('logi: ' + value); },
  }
}).then(result => {
  const exports = result.instance.exports;
}).catch(console.error);
