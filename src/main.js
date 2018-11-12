(async () => {
  try {
    const response = await fetch('../out/main.wasm');
    const bytes = await response.arrayBuffer();
    const wasm = await WebAssembly.instantiate(bytes);
    debugger;
    const functions = (wasm.instance || {}).exports || {};
    document.getElementById("container").textContent = functions.main(45);
  } catch (err) {
    console.error(err);
  }
})()