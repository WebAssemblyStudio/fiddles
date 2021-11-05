const { standardFibonacciInRust, betterDynamicFibonacciInRust } = wasm_bindgen;

const standardFibonacciInJavaScript = (num) => {
  if (num <= 1) return 1;

  return standardFibonacciInJavaScript(num - 1) + standardFibonacciInJavaScript(num - 2);
}

// https://medium.com/developers-writing/fibonacci-sequence-algorithm-in-javascript-b253dc7e320e
const betterMemoFibonacciInJavaScript = (num) => {
  memo = memo || {};

  if (memo[num]) return memo[num];
  if (num <= 1) return 1;

  return memo[num] = betterMemoFibonacciInJavaScript(num - 1, memo) + fibonacci(num - 2, memo);
}

function runApp() {
  const startTime = performance.now();
  const result = better_dynamic_fib(40);
  const endTime = performance.now();

  console.log(result);
  console.log(`WASM fibonacci took ${endTime - startTime} milliseconds`)
}

// Load and instantiate the wasm file, and we specify the source of the wasm
// file here. Once the returned promise is resolved we're ready to go and
// use our imports.
wasm_bindgen('../out/main_bg.wasm').then(runApp).catch(console.error);
