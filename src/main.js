const { alloc } = wasm_bindgen;

function runApp() {
  const count = 1000000;
  console.time('js');
  const array = new Array(count);
  for (let i = 0; i < count; i++) {
    array[i] = i;
  }
  console.timeEnd('js');
  console.time('wasm');
  alloc(count);
  console.timeEnd('wasm');
}

// Load and instantiate the wasm file, and we specify the source of the wasm
// file here. Once the returned promise is resolved we're ready to go and
// use our imports.
wasm_bindgen('../out/main_bg.wasm').then(runApp).catch(console.error);
