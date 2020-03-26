fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  instance = results.instance;

  wasmFactorial = function(n) {
    return instance.exports.factorial(n);
  }
}).catch(console.error);

function jsFactorial(n) {
  if(n==0) {
    return 1;
  } else {
    return n * jsFactorial(n-1);
  }
}

function jsFactorialNonRecursive(n) {
  let result = 1;

  for(let i = 1; i <= n; i++) {
    result *= i;
  }

  return result;
}

function trackTime(func, amount) {
  let average = arr => arr.reduce((a,b) => a + b, 0) / arr.length;

  let results = new Array();
  let executionTimes = new Array();

  for(let i = 0; i < amount; i++) {
    let start = performance.now();

    results.push(func());

    let end = performance.now();

    executionTimes.push(end - start);
  }

  return { result: average(results), executionTime: average(executionTimes) }
}

function startFactorial() {
  factorialInput = document.getElementById("factorialInput").value;
  amountInput = document.getElementById("amountInput").value;

  jsResult = 
        trackTime(() => jsFactorial(factorialInput), amountInput);
  jsNonRecursiveResult = 
        trackTime(() => jsFactorialNonRecursive(factorialInput), amountInput);
  wasmResult = 
        trackTime(() => wasmFactorial(factorialInput), amountInput);

  document.getElementById("jsNonRecursiveContainer").textContent =
        "JS-Non-Recursive-Execution: " + jsNonRecursiveResult.executionTime;
  document.getElementById("jsContainer").textContent =
        "JS-Execution: " + jsResult.executionTime;
  document.getElementById("wasmContainer").textContent =
        "WASM-Execution: " + wasmResult.executionTime;
}