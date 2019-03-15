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
  
  document.getElementById("calcBtn").addEventListener("click", () => {
    const n = Number(document.getElementById("n").value);
    if(!n) return;
    document.getElementById("output").value = exports.pi(n);
  });
}).catch(console.error);
