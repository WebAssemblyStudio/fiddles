WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  env: {
    log: function(value) {
      console.log(value);
    },
    abort: function(msg, file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  }
}).then(result => {
  const exports = result.instance.exports;
  exports.say();
});
