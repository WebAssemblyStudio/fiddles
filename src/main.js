const startTime = performance.now();//開始時間

fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  instance = results.instance;
  document.getElementById("container").textContent = instance.exports.main();
}).catch(console.error);

const endTime = performance.now();//終了時間

console.log(endTime - startTime);
