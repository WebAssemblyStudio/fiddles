
let BignumStackTop = 0;
let Memory;


WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  main: {
    sayHello() {
      console.log("Hello from WebAssembly!");
    },
    setBignumStack(startData, len) {
      console.log('setBignumStack!');
      console.log('startData:', startData);
      console.log('len:', len);
      console.log('BignumStackTop:', BignumStackTop);
    },
    add256() {
      console.log('add256!');
      console.log('BignumStackTop:', BignumStackTop.value);
      let left = 
    }
  },
  env: {
    abort(_msg, _file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  },
}).then(result => {
  const exports = result.instance.exports;
  Memory = exports.memory;
  BignumStackTop = exports.BignumStackTop;
  document.getElementById("container").textContent = "Result: " + exports.run_evm();
}).catch(console.error);
