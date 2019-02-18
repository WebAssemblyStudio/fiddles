WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  main: {
    log(v) {
      console.log(v);
    }
  },
  env: {
    abort(msg, file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  },
}).then(result => {
  const exports = result.instance.exports;
  console.log(exports.test(-1));
  console.log(exports.test(-100));
}).catch(console.error);
