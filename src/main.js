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
  const markAS1 = performance.now();
  const resultsAS = exports.fibonachi(40);
  const perfAS = performance.now() - markAS1;

  const markJS1 = performance.now();
  const resultJS = fibonachi(40);
  const perfJS = performance.now() - markJS1;

  document.getElementById("container").textContent = `Assembly Performance: ${perfAS}\n. JavaScript performance: ${perfJS}.`;
  }).catch(console.error);

function fibonachi(x) {
  if (x <= 0) {
    return 0;
  } else if (x === 1) {
    return 1;
  } else {
    return fibonachi(x - 1) + fibonachi(x - 2);
  }
}