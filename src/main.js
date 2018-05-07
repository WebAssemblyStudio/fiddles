WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  env: {
    abort: function(msg, file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    },
    JSMath: Math
  }
}).then(result => {
  const exports = result.instance.exports;
  document.getElementById("container").innerText = "Result: " + exports.lg();
});
