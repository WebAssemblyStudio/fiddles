async function main() {

  let { instantiateStreaming } = await import('https://cdn.jsdelivr.net/gh/cdetrio/assemblyscript@loader-export-es6/lib/loader/index.js');

  //WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  // use instantiateStreaming function from assemblyscript/lib/loader
  instantiateStreaming(fetch("../out/main.wasm"), {
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
  }).then(exports => {
    memory = exports.memory;
    document.getElementById("container").textContent = "Result: " + exports.__getString(exports.greet(3));
  }).catch(console.error);

}

main();