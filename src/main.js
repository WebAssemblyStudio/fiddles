async function main() {

let memory = new WebAssembly.Memory({ initial: 1024, maximum: 1024, shared: true });

WebAssembly.instantiateStreaming(fetch('../out/main.wasm'), {
  imports: { memory: memory }
}).then(results => {
  instance = results.instance;

  let data = new Uint32Array(instance.exports.memory.buffer);

  data[0] = 32;
  document.getElementById("container").textContent = instance.exports.test();

  for(let i =0; i < 16; i++)   console.log(`data[${i}]`, data[i]);

  
}).catch(console.error);

}

main();