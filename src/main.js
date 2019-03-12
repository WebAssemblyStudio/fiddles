const refs = {
  write(i, v) {
    refs.table[i] = v;
  },

  deref(i) {
    return refs.table[i];
  },

  alloc(i) {
    refs.table.push(0);
    return refs.length - 1;
  },

  table: []
};

fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes, {refs})).then(results => {
  instance = results.instance;
  document.getElementById("container").textContent = "running...";
  setTimeout(() => {
    let start = Date.now();
    instance.exports.bench_ref();
    let end = Date.now();
    document.getElementById("container").textContent = (end - start);

    setTimeout(() => {
      let start = Date.now();
      instance.exports.bench_mem();
      let end = Date.now();
      document.getElementById("container").textContent += "\n";
      document.getElementById("container").textContent += (end - start);
    }, 0);
  }, 0);



}).catch(console.error);

