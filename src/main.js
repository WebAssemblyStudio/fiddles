
function bench(fn, name, container) {
  let t = performance.now();
  fn();
  t = performance.now() - t;
  container.textContent += `${name}: ${t.toFixed(2)} ms\n`;
}

fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes, { env: { rand: Math.random } })).then(results => {
  const {
    randomize,
    bench_sort_100k, 
    bench_sort_10M,
  } = results.instance.exports;

  const container = document.getElementById("container");

  randomize();

  bench(bench_sort_100k, 'Rust sort 100_000 doubles  ', container);
  bench(bench_sort_10M,  'Rust sort 10_000_000 doubles', container);
}).catch(console.error);
