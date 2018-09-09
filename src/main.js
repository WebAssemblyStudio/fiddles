document.getElementById("container").innerText = "Loading"

WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  env: {
    sayHello() {
      console.log("Hello from WebAssembly!");
    },
    abort(msg, file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  },
  console: {
    logi(value) { console.log('logi: ' + value); },
    logf(value) { console.log('logf: ' + value); }
  }
}).then(result => {
  const exports = result.instance.exports;
  document.getElementById("container").innerText = "Result: " + exports.isMultipleOf(4, 2);
}).catch(err => {
  document.getElementById("container").innerText = "Error: " + err
});
