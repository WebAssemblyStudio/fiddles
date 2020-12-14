WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  main: {
    sayHello() {
      console.log("Hello from WebAssembly!");
    }
  },
  env: {
    abort(_msg, _file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  },
}).then(result => {
  const exports = result.instance.exports;
  
  let t = 0;

  t = performance.now();
  exports.benchOld();
  t = performance.now() - t;
  console.log('old str hash: ' + t + ' ms');

  t = performance.now();
  exports.benchNew();
  t = performance.now() - t;
  console.log('new str hash: ' + t + ' ms');
}).catch(console.error);
