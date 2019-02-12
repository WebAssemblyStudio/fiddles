WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  main: {
    logi(val) {
      console.log("int: " + val);
    },
    logf(val) {
      console.log("float: " + val);
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
