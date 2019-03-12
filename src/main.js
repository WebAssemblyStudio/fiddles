let mem;
const refs = {
  write(i, v) {
    refs.table[i];
  },

  deref(i) {
    return refs.table[i];
  },

  alloc(i, sz) {
    refs.table.push(0);
    return refs.length - 1;
  },

  mem_read(i) {
    return mem[i];
  },

  mem_write(i, v) {
    mem[i] = v;
  },

  table: []
};

fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes, {refs})).then(results => {
  instance = results.instance;
  mem = instance.exports.mem;

  document.getElementById("container").textContent = "running...";
  setTimeout(() => {
    let start = Date.now();
    instance.exports.bench_ref();
    let end = Date.now();
    document.getElementById("container").innerHTML = (end - start);

    setTimeout(() => {
      let start = Date.now();
      instance.exports.bench_mem();
      let end = Date.now();
      document.getElementById("container").innerHTML += "<br>bench_mem: ";
      document.getElementById("container").innerHTML += (end - start);
      setTimeout(() => {
        let start = Date.now();
        instance.exports.bench_mem_with_check();
        let end = Date.now();
        document.getElementById("container").innerHTML += "<br>bench_mem_with_check: ";
        document.getElementById("container").innerHTML += (end - start);

        setTimeout(() => {
          document.getElementById("container").innerHTML += "<br>bench_mem_indirect: ";
          let start = Date.now();
          instance.exports.bench_mem_indirect();
          let end = Date.now();
          document.getElementById("container").innerHTML += (end - start);
        }, 0);
      }, 0);
    }, 0);
  }, 0);



}).catch(console.error);

