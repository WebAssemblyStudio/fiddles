WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  main: {
    sayHello() {
      console.log("Hello from WebAssembly!");
    },

    // mem: new Uin32Array(100000),
  },
  env: {
    abort(msg, file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  },
}).then(result => {

  const ITERATIONS = 100000000;

  var startTime = performance.now();
  var a;
  for(let i = 0; i < ITERATIONS; i++) {
    a = i;
  }
  var  endTime = performance.now();
  document.getElementById("container").textContent += "js took: " + (endTime - startTime) + "ms ";

  const exports = result.instance.exports;
  startTime = performance.now();
  exports.testForLoop(ITERATIONS);
  endTime = performance.now();
  document.getElementById("container").textContent += "wasm took: " + (endTime - startTime) + "ms";
}).catch(console.error);
