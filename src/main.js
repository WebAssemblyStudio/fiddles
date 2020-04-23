// For more comments about what's going on here, check out the `hello_world`
// example at https://webassembly.studio/?f=gzubao6tg3
wasm_bindgen('../out/main_bg.wasm').then(result => {
  const container = document.getElementById("container");
  const grid = wasm_bindgen.Grid.new();

  benchmark("Rust", () => {
    const memory = wasm_bindgen.wasm.memory;

    const size = wasm_bindgen.get_max_size();
    const ptr = grid.data();
    const data = new Uint8Array(memory.buffer, ptr, size);
    if (data.includes(255)) console.log("got here");
    return data[Math.floor(Math.random() * size)];
  });

  benchmark("Js", () => {
    const size = wasm_bindgen.get_max_size();
    const data = run(size);
    return data[Math.floor(Math.random() * size)];
  });

}).catch(console.error);

function benchmark(label, fn) {
  let begin = performance.now();
  let result = fn();
  let elapsed = performance.now() - begin;

  container.innerHTML += `<p>Result for ${label}: <strong><span style="color:green">${result >>> 0}</span></strong>` +
                         `<br />Time taken: <strong>${elapsed} ms</strong></p>`;
}

function run(size) {
  const array = [];

  for (let i = 0; i < size; i++) {
    array[i] = Math.floor(Math.random() * 256);
  }

  return array;
}