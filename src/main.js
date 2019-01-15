let exports;

WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  main: {
    sayHello(s) {
      console.log(s);
    },
    sayHello1(s){
      console.log(s);
    }
  },
  env: {
    abort(msg, file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  },
}).then(result => {
   debugger;
  exports = result.instance.exports;
  exports.add(19, 23);
}).catch(console.error);
