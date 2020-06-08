var fetchresult = fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
);

document.getElementById('eval').addEventListener("click", () => {
  fetchresult.then(bytes => WebAssembly.instantiate(bytes)).then(results => {
    instance = results.instance;
    var num = Number(document.getElementById('num'));
    document.getElementById("container").textContent = instance.exports.fact(num);
  }).catch(console.error);
});