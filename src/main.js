WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  env: {
    log: function(val) {
      console.log(val);
    },
    abort: function(msg, file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  }
}).then(result => {
  // const exports = result.instance.exports;
  // document.getElementById("container").innerText = "Result: " + exports.add(19, 23);
}).catch(console.error);

