WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  main: {
    sayHello() {
      console.log("Hello from WebAssembly!");
    }
  },
  env: {
    abort(msg, file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  },
}).then(result => {
  const exports = result.instance.exports;
  const pointer = exports.getBuffer();
  const typedArray = new Uint8ClampedArray(exports.memory.buffer, pointer + 8, 3);
  console.log(typedArray);
}).catch(console.error);
