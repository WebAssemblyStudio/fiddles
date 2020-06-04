async function run() {
  let response = await fetch('../out/main.wasm');
  let bytes = await response.arrayBuffer();
  let module = await WebAssembly.instantiate(bytes, {
    env: {
      get_magic_number() {
        return 42;
      }
    }
  });
  let num = module.instance.exports.main();
  document.getElementById("container").textContent = num;
}

run();