WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  env: {
    sayHello: function() {
      console.log("Hello from WebAssembly!");
    },
    abort: function(msg, file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    },
    log: function(val) { return Math.log(val); }
  }
}).then(result => {
  const exports = result.instance.exports;

  exports.setup();
  
  console.time('wasm baseline');
  exports.baseline();
  console.timeEnd('wasm baseline');

  console.time('wasm stream');
  exports.stream();
  console.timeEnd('wasm stream');

  const ITERS = 10000000;
  const values = Array.from({ length: ITERS }, _ => (Math.round(Math.random() * ITERS) | 0));

  console.time('js baseline (JS side)');
  let acc = 0;
  for (let i = 0; i < ITERS; i++) {
    acc += (values[i] + 1) * 2 + 2;
  }
  console.timeEnd('js baseline (JS side)');

  console.time('js stream (JS side)');
  acc = values
      .map(x => x + 1)
      .map(x => x * 2)
      .map(x => x + 2)
      .reduce((a, b) => a + b, 0);
  console.timeEnd('js stream (JS side)');

}).catch(console.error);

