fetch('../out/main.wasm')
.then(response =>  response.arrayBuffer())
.then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  instance = results.instance;
  document.getElementById("container").textContent = instance.exports.main(22);
  //console.log(instance.exports.test(11,22))
}).catch(console.error);

async function test(){
  let f = await fetch('../out/main.wasm')
  let bytes = await f.arrayBuffer()
  console.log(bytes)
  WebAssembly.instantiate(bytes)
    .then(res=>{
      instance = res.instance;
      document.getElementById("container").textContent = instance.exports.main(22);
      //console.log(instance.exports.test(11,22))
    })
    
}
test()