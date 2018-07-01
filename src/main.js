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
  
  console.time('nativeLogTestf64');
  exports.nativeLogTestf64();
  console.timeEnd('nativeLogTestf64');

  console.time('jsLogTest (WASM side)');
  exports.jsLogTest();
  console.timeEnd('jsLogTest (WASM side)');

  console.time('nativeLogTestf32');
  exports.nativeLogTestf32();
  console.timeEnd('nativeLogTestf32');

  console.time('jsLogTest (JS side)');
  let acc = 0.0;
  for (let i = 0; i < 1000000; i++) {
    acc += Math.log(i);
  }
  console.timeEnd('jsLogTest (JS side)');

}).catch(console.error);

