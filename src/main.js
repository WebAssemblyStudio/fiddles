
let BignumStackTop = 0;
let Memory;
let BignumStackStartOffset;


WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  main: {
    sayHello() {
      console.log("Hello from WebAssembly!");
    },
    setBignumStack(startData, len) {
      console.log('setBignumStack!');
      console.log('startData:', startData);
      BignumStackStartOffset = startData;
      console.log('len:', len);
      console.log('BignumStackTop:', BignumStackTop);
    },
    add256() {
      console.log('add256!');
      console.log('BignumStackTop:', BignumStackTop.value);
      let stack_elem_a_pos = BignumStackStartOffset + 32*(BignumStackTop.value - 1);
      let stack_elem_b_pos = BignumStackStartOffset + 32*(BignumStackTop.value - 2);
      const elemA = new Uint8Array(Memory.buffer, stack_elem_a_pos, 32);
      const elemB = new Uint8Array(Memory.buffer, stack_elem_b_pos, 32);
      console.log('elemA:', elemA);
      console.log('elemB:', elemB);
    },
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
