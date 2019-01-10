WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  main: {
    logi(x) {
      console.log(x);
    }
  },
  env: {
    abort(msg, file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  },
}).then(result => {
  const exports = result.instance.exports;
}).catch(console.error);
