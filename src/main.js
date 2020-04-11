fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  instance = results.instance;

  const container = document.getElementById("container");  
  const LIMIT = 1000000000;
  
  benchmark("Sum from TS", () => instance.exports.sum(LIMIT));
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
    sum = (sum + i);
  }
  return sum;
}
