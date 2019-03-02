WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  main () {
    (new Game()).bind(this)
  },
  env: {
    abort(msg, file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  },
}).then(result => console.log("finish")).catch(console.error);
