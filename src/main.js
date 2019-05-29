async function getWasmFunctions () {
  const wasmPromise = fetch('../out/main.wasm');
  const imports = {
    seed: 1753817936,
    detail: 9,
    logi: i=>console.log("logi "+i),
    logf: f=>console.log("logf "+f.toPrecision(4)),
  };
  const instancePromise = WebAssembly
      .instantiateStreaming(wasmPromise, {i: imports});
  return (await instancePromise).instance.exports;
}
async function main() {
  const wasm = await getWasmFunctions();
  wasm.seed(0, 0);
  console.log(wasm.memory.buffer.byteLength/65536);
  // document.getElementById("container").textContent =
  //     field.map(e=>e.toFixed(2).substr(2)).join(' ');
}

main();