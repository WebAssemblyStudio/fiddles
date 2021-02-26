/** our runtime wasm binary */
const wasm = {
  file: fetch("../out/main.wasm")
}

/** Main entry point for javascript host */
function main() {
  WebAssembly
    .instantiateStreaming(wasm.file, imports)
    .then(run)
    .catch(console.error);
}

function run(result) {
  wasm.instance = result.instance
  wasm.exports = result.instance.exports
  console.log(wasm)

  const exports = result.instance.exports;
  document.getElementById("container").textContent = "Result: " + exports.add(19, 23);
}

function log() {
  console.log("Hello from WebAssembly!");
}

const imports = {
  main: {
    log
  },
  env: {
    abort(_msg, _file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  }
}

main()