WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  main: {
    sayHello() {
      console.log("Hello from WebAssembly!");
    }
  },
  env: {
    abort(msg, file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  },
}).then(result => {
  const exports = result.instance.exports;
  const t1 = new Date().getTime()
  const text = exports.add()
  console.log('WebAssembly cost time: ', new Date().getTime() - t1)
  const t2 = new Date().getTime()
  var returnVal = 1;
  for (var i = 0; i < 100000000; i++) {
    returnVal += i;
  }
  console.log('browser cost time: ', new Date().getTime() - t2)
  document.getElementById("container").textContent = "Result: " + text;
}).catch(console.error);
