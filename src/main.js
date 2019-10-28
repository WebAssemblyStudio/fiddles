//fetch('../out/main.wasm').then(response =>
//  response.arrayBuffer()
//).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
 // instance = results.instance;
 // document.getElementById("container").textContent = instance.exports.main();
//}).catch(console.error);

(async()=>{
  const codePromise=fetch('../out/main.wasm')
const {instance}=await WebAssembly.instantiateStreaming(codePromise)

const buffer=instance.exports.memory.buffer
const pointer=instance.exports.helloworld{}

let string=""
for(let i=pointer; buffer[i];i++){
  string+=string.fromCharCode(buffer[i])
}

document.getElementById('container').textContent=string
})()