fetch("../out/main.wasm")
.then(response => response.arrayBuffer())
.then(bytes => WebAssembly.instantiate(bytes, {
  env: {
    abort(_msg, _file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  },
}))
.then(result => {
  const exports = result.instance.exports;

  const test1 = exports.test1;
  const test2 = exports.test2;
  
  test1();
  console.time('division by uint64 constant 1e10 (mulh/shift)');
  test1();
  console.timeEnd('division by uint64 constant 1e10 (mulh/shift)');

  test2();
  console.time('division by uint64 constant 1e10 (normal)');
  test2();
  console.timeEnd('division by uint64 constant 1e10 (normal)');
})
.catch(console.error);
