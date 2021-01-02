fetch('../out/main.wasm')            //demo代码
.then(response =>  response.arrayBuffer())
.then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  instance = results.instance;
  document.getElementById("container").textContent = instance.exports.main(22);
  console.log(instance.exports.test(11,22))
}).catch(console.error);

async function test(){     //修改回调，看的清楚一些
  let f = await fetch('../out/main.wasm')
  let bytes = await f.arrayBuffer()
  WebAssembly.instantiate(bytes)
    .then(res=>{
      instance = res.instance;
      document.getElementById("container").textContent = instance.exports.main(22);
      console.log(instance.exports.test(11,22))
    })
    
}
test()