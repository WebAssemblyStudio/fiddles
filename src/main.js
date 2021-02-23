WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  main: {
    sayHello() {
      console.log("Hello from WebAssembly!");
    }
  },
  env: {
    abort(_msg, _file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  },
}).then(result => {
  const exports = result.instance.exports
      const player = [46 , 176]
  const enemy = [37 , 198]
  document.getElementById("container").textContent = "Result from webassembly: " + exports.add(46, 176 , 37 , 198);
}).catch(console.error);
