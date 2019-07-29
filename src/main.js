
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

      result8 = elemA[31] + elemB[31];
      const resultBytes = new Uint8Array(32);
      resultBytes[31] = result8;

      let outOffset = stack_elem_b_pos;
      // pop 2 push 1, top is reduced by 1;
      BignumStackTop = BignumStackTop - 1;
      const outputBytes = new Uint8Array(Memory.buffer, outOffset, 32);
      outputBytes.set(resultBytes);
    },
    finish(returnOffset) {
      const returnVal = new Uint8Array(Memory.buffer, returnOffset, 32);
      let returnHex = '';
      for (var i = 0; i < 32; i++) {
        if (returnVal[i] < 16) returnHex += '0';
            returnHex += returnVal[i].toString(16);
      }
      console.log("return val:", returnHex);
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
