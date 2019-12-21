let instance = undefined;
fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  instance = results.instance;
  //document.getElementById("container").textContent = instance.exports.main();
}).catch(console.error);
let n1 = document.getElementById("n1");
let n2 = document.getElementById("n2");
let addButton = document.getElementById("addButton");
let container = document.getElementById("container");
addButton.onclick = () => 
{
  if (instance)
  {
    container.textContent = instance.exports.Add(n1.value, n2.value);
  }
}
