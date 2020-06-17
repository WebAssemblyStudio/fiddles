WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  main: {
    logBool(b) {
      console.log('logBool: ' + (b ? 'true' : false));
    }
  },
  env: {
    abort(_msg, _file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  },
}).then(result => {
  const exports = result.instance.exports;
}).catch(console.error);
