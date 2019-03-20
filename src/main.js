const memory = new WebAssembly.Memory({ initial: 10, maximum: 100 });
const importInimportObj = {
  main: {
    sayHello(memory) {
      console.log("Hello from WebAssembly!" + Math.random(), memory);
    },
  },
  env: {
    abort(msg, file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    },
    memory
  }
}
WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), importInimportObj).then(result => {
  const exports = result.instance.exports;
  document.getElementById("container").textContent = "Result: " + exports.add(19, 23);

  // const inU32 = new Uint32Array(memory.buffer);
  // for (let i = 0; i < inU32.length; i += 1) {
  //   inU32[i] = (i + 1) * 8
  // }
  // console.log(inU32);
  // exports.wasmLoop(inU32, outU32, 2, 2);
  // console.log(outU32);
}).catch(console.error);
