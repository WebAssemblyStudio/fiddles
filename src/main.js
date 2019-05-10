(async ()=>{


let wasmModule =await WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  main: {
    sayHello() {
      console.log("Hello from WebAssembly!" );
    }
  },
  env: {
    abort(msg, file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  },
});


const exports = wasmModule.instance.exports;
document.getElementById("container").textContent = "Result: " + exports.add(19, 23);

})();