const { run } = wasm_bindgen;

// For more comments about what's going on here, check out the `hello_world`
// example at https://webassembly.studio/?f=gzubao6tg3
wasm_bindgen('../out/main_bg.wasm').then(result => {
  const exports = wasm_bindgen;
  // document.getElementById("container").textContent = "Result: " + exports.add(19, 23);
  const container = document.getElementById("container");
  
  benchmark("Sum from TS", () => exports.run());

}).catch(console.error);

function benchmark(label, fn) {
  let begin = performance.now();
  let result = fn();
  let elapsed = performance.now() - begin;

  container.innerHTML += `<p>Result for ${label}: <strong><span style="color:green">${result >>> 0}</span></strong>` +
                         `<br />Time taken: <strong>${elapsed} ms</strong></p>`;
}