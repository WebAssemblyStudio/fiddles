async function run() {
  let response = await fetch('../out/main.wasm');
  let bytes = await response.arrayBuffer();
  let module = await WebAssembly.instantiate(bytes);
  let num = module.instance.exports.add(1,1);
  document.getElementById("container").textContent = num;
}

run();