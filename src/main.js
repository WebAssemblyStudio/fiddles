(async ()=>{
  const codePromise = fetch('../out/main.wasm')
  const module = await WebAssembly.instantiateStreaming(codePromise)
  
  const buffer = new Uint8Array(module.instance.exports.memory.buffer)

  const pointer = module.instance.exports.hi()

  let string = ""

  for(let i = pointer; buffer[i]; i++){
      string += String.fromCharCode(buffer[i])
  }
  console.log(string);

  document.querySelector("#container").textContent = string;
})()