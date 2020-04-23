const { run } = wasm_bindgen;

// For more comments about what's going on here, check out the `hello_world`
// example at https://webassembly.studio/?f=gzubao6tg3
wasm_bindgen('../out/main_bg.wasm').then(result => {
  const container = document.getElementById("container");
  
  benchmark("Sum from TS", () => {
    const memory = wasm_bindgen.wasm.memory;

    const size = wasm_bindgen.get_max_size();
    const ptr = wasm_bindgen.run();
    const data = new Uint8Array(memory.buffer, ptr, size);
    
    alert(data[0]);
  });

}).catch(console.error);

function benchmark(label, fn) {
  let begin = performance.now();
  let result = fn();
  let elapsed = performance.now() - begin;

  container.innerHTML += `<p>Result for ${label}: <strong><span style="color:green">${result >>> 0}</span></strong>` +
                         `<br />Time taken: <strong>${elapsed} ms</strong></p>`;
}