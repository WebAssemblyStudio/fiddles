const imports = {
  env: {
    seed: Date.now,
    abort(_msg, _file, line, column) {
      console.error('abort called at index.ts:' + line + ':' + column)
    }
  }
}

WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), imports).then(result => {
  const exports = result.instance.exports;
  console.log(exports.rand());
}).catch(console.error);
