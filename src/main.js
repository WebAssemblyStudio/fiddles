var number=0;
let elem= document.getElementById("ip-no");
console.log(elem);
elem.onchange= function(e){
  let newNumber=e.target.value;
  getWasm(newNumber)
}
getWasm(12)
function getWasm(number){
  console.log("called")
fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => {console.log(bytes); return WebAssembly.instantiate(bytes)}).then(results => {
  console.log(results,results.instance)
  instance = results.instance;
  document.getElementById("container").textContent = instance.exports.main(number,"HELLO!");
}).catch(console.error);
}