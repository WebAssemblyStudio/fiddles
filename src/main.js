WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  main: {

  },
  env: {
    abort(_msg, _file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  },
}).then(result => {

}).catch(console.error);
