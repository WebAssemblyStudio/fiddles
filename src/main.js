function bench(fn, name, container) {
  // warm-up
  fn();

  let t;
  t = performance.now();
  fn();
  t = performance.now() - t;
  container.textContent += `${name}: ${t.toFixed(4)}ms \n`;
}


WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  env: {
    abort(_msg, _file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  },
}).then(result => {
  const { bench1, bench2 } = result.instance.exports;
  const container = document.getElementById("container");


  bench(bench1, 'bench1', container);
  bench(bench2, 'bench2', container);

}).catch(console.error);
