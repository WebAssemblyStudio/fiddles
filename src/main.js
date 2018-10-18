WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  env: {
    abort(msg, file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  },
  main: {
    logc(value) { console.log('char: ' + String.fromCharCode(value)); },
  }
}).then(result => {
  const exports = result.instance.exports;
}).catch(console.error);
