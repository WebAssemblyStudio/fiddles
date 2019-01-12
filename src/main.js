WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  main: {
    log(v) {
      console.log('SOME:' + v >>> 0);
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
