WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  env: {
    sayHello: function() {
      console.log("Hello from WebAssembly!");
    },
    abort: function(msg, file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  }
}).then(result => {
  const exports = result.instance.exports;
  
  console.time('loop1');
  exports.loop1(1, 3, 1000000);
  console.timeEnd('loop1');

  console.time('loop2');
  exports.loop2(1, 3, 1000000);
  console.timeEnd('loop2');

}).catch(console.error);

