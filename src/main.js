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
  // document.getElementById("container").textContent = "Result: " + exports.add(19, 23);
  const container = document.getElementById("container");
  
  const LIMIT = 1000000000;
  
  benchmark("Sum from TS", () => exports.sum(LIMIT));

  benchmark("Sum from JS", () => sum(LIMIT));

}).catch(console.error);

function benchmark(label, fn) {
  let begin = performance.now();
  let result = fn();
  let elapsed = performance.now() - begin;

  container.innerHTML += `<p>Result for ${label}: <strong><span style="color:green">${result >>> 0}</span></strong>` +
                         `<br />Time taken: <strong>${elapsed} ms</strong></p>`;
}

function sum(limit) {
  limit = limit;
  let sum = 0;
  for (let i = 0; i < limit; i++) {
    sum = (sum + i) >>> 0;
  }
  return sum;
}
