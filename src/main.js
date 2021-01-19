(async ()=>{
  // const codePromise = fetch('../out/main.wasm')
  // const module = await WebAssembly.instantiateStreaming(codePromise)
  let pointer;
  let buffer;

  fetch('../out/main.wasm')
  .then(res => {
    if (res.ok)
      return res.arrayBuffer();
    throw new Error(`Unable to fetch WASM.`);
  })
  .then(bytes => {
    return WebAssembly.compileStreaming(bytes);
  })
  .then(module => {
    return WebAssembly.instantiateStreaming(module);
  })
  .then(instance => {
      buffer = new Uint8Array(instance.exports.memory.buffer)

      pointer = instance.exports.hi();
  });


  let string = ""

  for(let i = pointer; buffer[i]; i++){
      string += String.fromCharCode(buffer[i])
  }
  console.log(string);

  document.querySelector("#container").textContent = string;
})()