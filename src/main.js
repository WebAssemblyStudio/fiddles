let time = Date.now();
fetch('../out/main.wasm').then(response => {
  document.getElementById("container").textContent += `Time to load the file: ${Date.now() - time}\n`;
  time = Date.now();
  return response.arrayBuffer()
}).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  document.getElementById("container").textContent += `Time to load file: ${Date.now() - time}\n`;
  time = Date.now();

  resultSum = results.instance.exports.sumSequence(20);
  document.getElementById("container").textContent += `Result of the computation: ${resultSum}\n`;

  document.getElementById("container").textContent += `Time to compute: ${Date.now() - time}\n`;
}).catch(console.error);
