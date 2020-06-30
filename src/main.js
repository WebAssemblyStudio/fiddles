function invSqrtF64(x) {
  return 1 / Math.sqrt(x);
}

WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  env: {
    abort(_msg, _file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  },
}).then(result => {
  const { invSqrtF32 } = result.instance.exports;

  console.log("invSqrt32(1e-12): " + invSqrtF32(1e-12));
  console.log("invSqrt64(1e-12): " + invSqrtF64(1e-12));
  console.log(`invSqrt32(${7.01e-46}): ` + invSqrtF32(7.01e-46));
  console.log(`invSqrt64(${7.01e-46}): ` + invSqrtF64(7.01e-46));
  console.log(`invSqrt32(${7e-46}): ` + invSqrtF32(7e-46));
  console.log(`invSqrt64(${7e-46}): ` + invSqrtF64(7e-46));
  console.log("invSqrt32(0): "  + invSqrtF32(0));
  console.log("invSqrt64(0): "  + invSqrtF64(0));
}).catch(console.error);
