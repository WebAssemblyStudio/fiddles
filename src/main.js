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

  console.time('jsLogTest');
  exports.jsLogTest();
  console.timeEnd('jsLogTest');

  console.time('nativeLogTestf32');
  exports.nativeLogTestf32();
  console.timeEnd('nativeLogTestf32');

}).catch(console.error);

