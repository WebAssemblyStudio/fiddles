WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  env: {
    log: function(v) {
      console.log(v);
    },
    abort: function(msg, file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  }
}).then(result => {
}).catch(console.error);

