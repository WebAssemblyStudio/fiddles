let wasmMemory = new WebAssembly.Memory({
  initial: 10000,
});

const importObject = {
  env: {
    abort(_msg, _file, line, column) {
      console.error("abort called at index.ts:" + line + ":" + column);
    },
    memory: wasmMemory,
  },
  Math,
};

WebAssembly.instantiateStreaming(
  fetch("../out/main.wasm"),
  importObject
).then((res) => {
  res.instance.exports.init(512);
  res.instance.exports.populate();
});