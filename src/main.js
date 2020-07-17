function sumSequence(n) {
  if (n < 2)
    return 1;
  else
    return n + sumSequence(n-1) + sumSequence(n-2);
}

// complexity: O(2^n) - with n=40 sumsequence is called about 300 000 000 times
let time = Date.now();
fetch('../out/main.wasm').then(response => {
  document.getElementById("container").textContent += `Time to load the file: ${Date.now() - time}ms\n`;
  time = Date.now();
  return response.arrayBuffer()
}).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  document.getElementById("container").textContent += `Time to load file: ${Date.now() - time}ms\n`;
  time = Date.now();

  resultSum = results.instance.exports.sumSequence(40);
  document.getElementById("container").textContent += `Result of the WASM computation: ${resultSum}\n`;
  document.getElementById("container").textContent += `Time to WASM-compute: ${Date.now() - time}ms\n`;
  time = Date.now();


  resultSum = sumSequence(40);
  document.getElementById("container").textContent += `Result of the js computation: ${resultSum}\n`;
  document.getElementById("container").textContent += `Time to compute: ${Date.now() - time}ms\n`;
  time = Date.now();
}).catch(console.error);
