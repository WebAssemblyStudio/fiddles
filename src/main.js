let memory = new WebAssembly.Memory({
  initial: 2 * 1024 * 1024 >>> 16, // prealloc 2 MB
});

const importObject = {
  env: {
    memory,
    seed: Date.now,

    abort(_msg, _file, line, column) {
      console.error("abort called at index.ts:" + line + ":" + column);
    },
  }
};

WebAssembly.instantiateStreaming(
  fetch("../out/main.wasm"),
  importObject
).then((res) => {
  res.instance.exports.init(512);
  res.instance.exports.populate();
});