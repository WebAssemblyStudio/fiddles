WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  env: {
    sayHello: function() {
      console.log("Hello from WebAssembly!");
    },
    abort: function(msg, file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  }
}).then(result => {
  const exports = result.instance.exports;
  var r = new Int32Array([1,2]);
  document.getElementById("container").innerText = "Result: " + exports.fib(new Int32Array([1,2]));
});
