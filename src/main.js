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
  const fibA = performance.now();
  const fibASResult = exports.fibonaci(40);
  const timeAS = performance.now() - fibA;

  const fibB = performance.now();
  const fibJSResult = fibonachi(40);
  const timeJS = performance.now() - fibB;

  document.getElementById("container").textContent = `WASM: ${timeAS}, JS: ${timeJS}`;
}).catch(console.error);

function fibonachi(x) {
  if (x <= 0) {
    return 0;
  } else if (x === 1) {
    return 1;
  } else {
    return fibonachi(x - 1) + fibonachi( x - 2);
  }
}