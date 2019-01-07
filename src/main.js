WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  main: {
    INIT_64K_PAGECOUNT: 1,
    MAX_64K_PAGECOUNT: 256,
    X_BUFFER_SIZE: 5000,

    logger(value) {
      console.log('[GS.AS]', value);
    }
  },
  env: {
    abort(msg, file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  },
}).then(result => {
  const exports = result.instance.exports;

  console.log("getAligned(0):");
  exports.getAligned(0);
  console.log("getAligned(1):");
  exports.getAligned(1);
  console.log("getAligned(2):");
  exports.getAligned(2);
  console.log("getAligned(3):");
  exports.getAligned(3);
  console.log("getAligned(0xffffffff):");
  exports.getAligned(0xffffffff);

}).catch(console.error);
