let exports;

WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  main: {
    sayHello(ptr) {
      exports.hello(ptr);
    },
    log(value){
      console.log(value);
    }
  },
  env: {
    abort(msg, file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  },
}).then(result => {
  exports = result.instance.exports;
  exports.add(19, 23);
}).catch(console.error);
