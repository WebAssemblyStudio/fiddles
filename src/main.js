const { standardFibonacciInRust, betterDynamicFibonacciInRust } = wasm_bindgen;

const standardFibonacciInJavaScript = (num) => {
  if (num <= 1) return 1;

  return standardFibonacciInJavaScript(num - 1) + standardFibonacciInJavaScript(num - 2);
}

function runApp() {
  const standardNumberIterations = 40;

  const standardJsStartTime = performance.now();
  const standardJsResult = standardFibonacciInJavaScript(standardNumberIterations);
  const standardJsEndTime = performance.now();
  const standardJsTimeTaken = standardJsEndTime - standardJsStartTime;

  const standardRustStartTime = performance.now();
  const standardRustResult = standardFibonacciInRust(standardNumberIterations);
  const standardRustEndTime = performance.now();
  const standardRustTimeTaken = standardRustEndTime - standardRustStartTime;


  console.log('----------- Time in ms ---------------');
  console.log('Standard JS: ' + standardJsTimeTaken);
  console.log('Standard Rust: ' + standardRustTimeTaken);
  console.log('');
  console.log('🔥')
  console.log('');
  console.log('----------------------------------');
}

// Load and instantiate the wasm file, and we specify the source of the wasm
// file here. Once the returned promise is resolved we're ready to go and
// use our imports.
wasm_bindgen('../out/main_bg.wasm').then(runApp).catch(console.error);
