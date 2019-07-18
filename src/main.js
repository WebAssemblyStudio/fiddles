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
  const exports = result.instance.exports;
  document.getElementById("container").textContent = "Result: " + exports.add(19, 23);
  console.log(exports.__rtti_base.value)
  for(let i = 0; i < 5000; i++) exports.fill(i)
  
  console.log(exports.count())
  console.log(exports.__rtti_base.value)
  
}).catch(console.error);
