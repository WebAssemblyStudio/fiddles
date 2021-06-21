const mem = new WebAssembly.Memory({initial:1,maximum:1});
const dv = new Float32Array(mem.buffer);

dv.setFloat32(8, 1.0000000, true);



fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes,{
  		env: { memory: mem}
})).then(instance=>{
  document.body.innerHTML=instance.exports.printFloatStoredAt(0);
}).catch(console.error);
