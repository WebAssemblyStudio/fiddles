WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  main: {
    log(count) {
      console.log("count: " + count);
    }
  },
  env: {
    abort(_msg, _file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  },
}).then(result => {
  const exports = result.instance.exports;
  exports.test();
}).catch(console.error);
