WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  env: {
    abort(_msg, _file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  },
}).then(result => {
  const exports = result.instance.exports;
  //console.log('ptr: ' + exports.createUint8Array(6553600)); // OK
  console.log('ptr: ' + exports.createUint8Array(6553600 + 1)); // RuntimeError
}).catch(console.error);
