let buffer = null;

WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  main: {
    _print(ptr, len) {
      const arr = new Uint8Array(buffer, ptr, len);
      console.log('bytes: [' + arr + ']');
      console.log('str: ' + new rray(arr).map(c => String.fromCharCode(c)).join(''));
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
  document.getElementById("container").textContent = "Result: " + exports.main();
}).catch(console.error);
