// 讀取檔案
fetch('../out/main.wasm').then(response => {
  // 從物件中取得二進制緩衝
  return response.arrayBuffer()
}
// 
).then(bytes => WebAssembly.instantiate(bytes))
  .then(results => {
  console.log(results)
  instance = results.instance;
  console.log(instance)
  document.getElementById("container").textContent = instance.exports.sum(6,10);
}).catch(console.error);
