WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  main: {
    f64toI32_js(x) { return x | 0 }
  },
  env: {
    abort(_msg, _file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  },
}).then(result => {
  const exports = result.instance.exports;
  
  console.time('double to int (wrap style) (JS)');
  for (let d = 0; d < 1e8; d++) {
    exports.ftoint_js(d);
  }
  console.timeEnd('double to int (wrap style) (JS)');

  console.time('double to int (wrap style) (Wasm)');
  for (let d = 0; d < 1e8; d++) {
    exports.ftoint_js(d);
  }
  console.timeEnd('double to int (wrap style) (Wasm)');

}).catch(console.error);
