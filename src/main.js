const importObject ={
  env:{
logResult(result){
  console.log(result);
}
  }
}


fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes,importObject))
.then(results => {
  instance = results.instance;
  document.getElementById("container")
  .textContent = instance.exports.add_one(41);
}).catch(console.error);
