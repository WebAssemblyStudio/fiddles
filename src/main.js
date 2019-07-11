
// TODO: use wabt.js to pull function from keccak.wat,
// and add it to the main.wasm module

const FILENAME = "../src/keccak.wat"

const wabt = new WabtModule();
let myModule;

fetch(FILENAME).then(response => {
  return response.text();
}).then(watfile => {
  console.log('got watfile:', watfile);
  var features = {'mutable_globals':false};
  myModule = wabt.parseWat(FILENAME, watfile, features);
  myModule.resolveNames();

  console.log('parsed wat..')
  myModule.validate();

  return fetch("../out/main.wasm");
}).then(response => {
  console.log('fetched main.wasm:', response);

  return response.json();
}).then(main_wasm => {

  // main_wasm is a buffer passed to instantiateStreaming


  const wasmBinary = myModule.toBinary({ write_debug_names: true });
  console.log('got wasm binary..')
  return wasmBinary;

}).then(wasmBinary => {

  return WebAssembly.instantiate(wasmBinary.buffer, {
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
    });
}).then(result => {
  const exports = result.instance.exports;
  document.getElementById("container").textContent = "Result: " + exports.add(19, 23);
}).catch(console.error);



/*
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
  document.getElementById("container").textContent = "Result: " + exports.add(19, 23);
}).catch(console.error);
*/
