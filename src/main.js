WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  main: {
    console_log(s) {
      console.log(s);
    }
  },
  env: {
    abort(_msg, _file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  },
}).then(result => {
  const exports = result.instance.exports;
  exports._start();
}).catch(console.error);
