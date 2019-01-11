WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  main: {
    log(val) {
      console.log('0x' + (val >>> 0).toString(16).toUpperCase());
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
