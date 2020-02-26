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

  const calcNums = new Int32Array([1, 2, 3, 4, 5, 0x7fffffff]);
  console.log('Input array data to be summed:', calcNums);

  console.log(result.instance);

// the pointer points to the memory location in WASM context
const ptr = result.module.newArray(calcNums);

// call the WASM module to execute the processing
exports.sum(ptr);

// make sure you provide the same TypedArray subclass constructor like in line 15
const expectedSummedArray = exports.getArray(Int32Array, ptr);

// directly access the processed array
console.log('expectedSummedInt32Array', expectedSummedArray);

// free memory in WASM context
exports.freeArray(ptr);

  document.getElementById("container").textContent = "Result: " + exports.add(19, 23);
}).catch(console.error);
