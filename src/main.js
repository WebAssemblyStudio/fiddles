function add_js(n) {
  let s = 0;
  for (let i = n; i > 0; i -= 1) {
    s = (s + i) % 1000007;
  }
  return s;
}

WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  env: {
    abort(_msg, _file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  },
}).then(result => {
  const exports = result.instance.exports;

  const n = 100000000;

  // warm-up wasm
  exports.add(n);
  exports.add(n);

  console.time('add (wasm)');
  exports.add(n);
  console.timeEnd('add (wasm)');

  // warm-up js
  add_js(n);
  add_js(n);

  console.time('add (js)');
  add_js(n);
  console.timeEnd('add (js)');

  console.log('Bench done! See your console');

}).catch(console.error);
