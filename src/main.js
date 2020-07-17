'use strict'; 

function fibo(n) {
    if (n < 2) {
        return 1
    }
    let result = 1
    while(n > 1) {
        result += fibo(n-1)
        n = n-2
    }
    return result
}

// complexity: O(2^n) - with n=40 fibo is called about 300 000 000 times
let time = Date.now();
fetch('../out/main.wasm').then(response => {
  document.getElementById("container").textContent += `Time to load the file: ${Date.now() - time}ms\n`;
  time = Date.now();
  return response.arrayBuffer()
}).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  document.getElementById("container").textContent += `Time to load file: ${Date.now() - time}ms\n`;
  time = Date.now();

  let resultSum;
  resultSum = results.instance.exports.fibo(40);
  document.getElementById("container").textContent += `Result of the C-WASM computation: ${resultSum}\n`;
  document.getElementById("container").textContent += `Time to C-WASM-compute: ${Date.now() - time}ms\n`;
  time = Date.now();


  resultSum = fibo(40);
  document.getElementById("container").textContent += `Result of the js computation: ${resultSum}\n`;
  document.getElementById("container").textContent += `Time to js-compute: ${Date.now() - time}ms\n`;
  time = Date.now();
}).catch(console.error);
