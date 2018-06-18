WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  env: {
    log: function(value) {
      console.log(value);
    },
    log16: function(lo, hi) {
      console.log('0x' + (hi >>> 0).toString(16) + (lo >>> 0).toString(16));
    },
    abort: function(msg, file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  }
}).then(result => {
  const exports = result.instance.exports;
  document.getElementById("container").innerText = "Result: " + exports.add(19, 23);
}).catch(console.error);

