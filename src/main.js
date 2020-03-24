fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  instance = results.instance;

  wasmFactorial = function(n) {
    return instance.exports.factorial(n);
  }
}).catch(console.error);

function jsFactorial(n) {
  if(n<=1) {
    return n;
  } else {
    return n * jsFactorial(n-1);
  }
}

function trackTime(func, amount) {
  let start = performance.now();
  
  let result = func();

  for(let i = 1; i < amount; i++) {
    let result = func();
  }

  let end = performance.now();

  let executionTime = end - start;

  return {result: result, executionTime: executionTime}
}

function startFactorial() {
  factorialInput = document.getElementById("factorialInput").value;
  amountInput = document.getElementById("amountInput").value;

  jsResult = trackTime(() => jsFactorial(factorialInput), amountInput);
  wasmResult = trackTime(() => wasmFactorial(factorialInput), amountInput);

  document.getElementById("jsContainer").textContent = "JS-Execution: " + jsResult.executionTime;
  document.getElementById("wasmContainer").textContent = "WASM-Execution: " + wasmResult.executionTime;
}