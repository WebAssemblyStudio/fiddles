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
  debugger
  const exports = result.instance.exports;
      console.log(JSON.stringify(result.instance, null, 5))
  
  document.getElementById("container").textContent = doSmth(exports);
}).catch(console.error);

function doSmth (instance) {
    let fnPtr = instance.doSmth();
    return fnPtr;
}