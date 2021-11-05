const { standardFibonacciInRust, betterDynamicFibonacciInRust } = wasm_bindgen;

const standardFibonacciInJavaScript = (num) => {
  if (num <= 1) return 1;

  return standardFibonacciInJavaScript(num - 1) + standardFibonacciInJavaScript(num - 2);
}

// https://medium.com/developers-writing/fibonacci-sequence-algorithm-in-javascript-b253dc7e320e
const betterMemoFibonacciInJavaScript = (num, memo) => {
  memo = memo || {};

  if (memo[num]) return memo[num];
  if (num <= 1) return 1;

  return memo[num] = betterMemoFibonacciInJavaScript(num - 1, memo) + betterMemoFibonacciInJavaScript(num - 2, memo);
}

function runApp() {
  const standardNumberIterations = 40;
  const betterNumberIterations = 50;

  const standardJsStartTime = performance.now();
  const standardJsResult = standardFibonacciInJavaScript(standardNumberIterations);
  const standardJsEndTime = performance.now();
  const standardJsTimeTaken = standardJsEndTime - standardJsStartTime;

  const betterJsStartTime = performance.now();
  const betterJsResult = betterMemoFibonacciInJavaScript(betterNumberIterations);
  const betterJsEndTime = performance.now();
  const betterJsTimeTaken = betterJsEndTime - betterJsStartTime;

  const standardRustStartTime = performance.now();
  const standardRustResult = standardFibonacciInRust(standardNumberIterations);
  const standardRustEndTime = performance.now();
  const standardRustTimeTaken = standardRustEndTime - standardRustStartTime;

  const betterRustStartTime = performance.now();
  const betterRustResult = betterDynamicFibonacciInRust(betterNumberIterations);
  const betterRustEndTime = performance.now();
  const betterRustTimeTaken = betterRustEndTime - betterRustStartTime;

  console.log('----------- Time in ms ---------------');
  console.log('Standard JS: ' + standardJsTimeTaken);
  console.log('Standard Rust: ' + standardRustTimeTaken);
  console.log('');
  console.log('🔥')
  console.log('');
  console.log('Better JS: ' + betterJsTimeTaken);
  console.log('Better Rust: ' +  betterRustTimeTaken);
  console.log('----------------------------------');
}

// Load and instantiate the wasm file, and we specify the source of the wasm
// file here. Once the returned promise is resolved we're ready to go and
// use our imports.
wasm_bindgen('../out/main_bg.wasm').then(runApp).catch(console.error);
