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
  document.getElementById("container").innerHTML = 
    "<p>len for Int32Array: " + exports.go() + 
    "<br>len for Float64Array: " + exports.go2() + 
    "</p>";
}).catch(console.error);
