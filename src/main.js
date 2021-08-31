const { greet } = wasm_bindgen;

function runApp() {
  const start = performance.now();
  var x  =0;
  for (let i = 0; i<1000000000; i+=1){
      x +=1
  }
  const end = performance.now();

  alert(`${end-start}ms`)
  const startWASM = performance.now();
  greet();
  const endWASM = performance.now();
  alert(`${endWASM-startWASM}ms`)
}

// Load and instantiate the wasm file, and we specify the source of the wasm
// file here. Once the returned promise is resolved we're ready to go and
// use our imports.
wasm_bindgen('../out/main_bg.wasm').then(runApp).catch(console.error);
