
WebAssembly.instantiateStreaming(fetch("../out/main_with_keccak.wasm"), {
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
  const wasm_returned = exports.mpt_verify(19, 23);
  document.getElementById("container").textContent = "Result: " + wasm_returned + " (0x" + wasm_returned.toString(16) + ")";
}).catch(console.error);

