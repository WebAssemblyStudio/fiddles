let buffer = null;

WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  main: {
    _print(ptr, len) {
      const arr = new Uint8Array(buffer, ptr, len);
      console.log('ptr: ' + (ptr >>> 0));
      console.log('byteLength: ' + (len >>> 0));
      console.log('bytes: [' + arr + ']');
      console.log('str result: "' + [...arr].map(c => String.fromCharCode(c)).join('') + '"');
    }
  },
  env: {
    abort(_msg, _file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  },
}).then(result => {
  const exports = result.instance.exports;
  buffer = exports.memory.buffer;

  exports.run();

}).catch(console.error);
