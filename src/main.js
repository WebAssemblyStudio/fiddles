WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  main: {},
  env: {
    abort(_msg, _file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  },
}).then(result => {

  const exports = result.instance.exports;
  const isPrime = exports.isPrime;

  
  document.getElementById("container").textContent = "Result: " + exports.add(19, 23);

}).catch(console.error);
