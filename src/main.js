const { greet, calculate } = wasm_bindgen;

function wasm() {
  const wasm_begin = performance.now()
  const wasm_result = calculate();
  const wasm_end = performance.now()

  return {
    wasm_result, wasm_perf: wasm_end - wasm_begin
  }
}

function runApp() {
  const begin = performance.now()
  const arr = Array(500_000).fill(0);
  const js_result = arr.reduce((acc, elem, index) => index % 42 == 0 ? acc + 1 : acc, 0)
  const end = performance.now();
  const js_perf = end - begin;

  if (wasm().wasm_result !== js_result) {
    throw Error('Something went wrong ...')
  }


  console.log({ js_perf, js_result, ...wasm() });
  console.log(`WASM is ${Math.floor(js_perf / wasm().wasm_perf)} times faster`)
}

// Load and instantiate the wasm file, and we specify the source of the wasm
// file here. Once the returned promise is resolved we're ready to go and
// use our imports.
wasm_bindgen('../out/main_bg.wasm').then(runApp).catch(console.error);
