WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  env: {
    sayHello: function() {
      console.log("Hello from WebAssembly!");
    },
    abort: function(msg, file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  },
  console: {
    logv: function (lo1, lo2, hi1, hi2) {
      console.log(
        '0x' + 
        hi2.toString(16).padStart(8, '0') + 
        hi1.toString(16).padStart(8, '0') + 
        lo2.toString(16).padStart(8, '0') + 
        lo1.toString(16).padStart(8, '0')
      );
    }
  }
}).then(result => {
  const exports = result.instance.exports;
  document.getElementById("container").innerText = "Result: " + exports.add(19, 23);
}).catch(console.error);

