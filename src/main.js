(async() => {
  const codePromise = fetch('../out/main.wasm')
  const {instance} = await WebAssembly.instantiateStreaming(codePromise)
  //console.log(module)

//check the console for other memory
//exports.helloworld
//exports.main
//exports.memory

// all the data [123444, 432365, 33, 12, 2, 'H', 'E', 'L']
  const buffer = new Uint8Array(instance.exports.memory.buffer) // buffer array

// just helloworld data, not the string but the memory block containing helloworld data
  const pointer = instance.exports.helloworld()


  let string = ""
  for (let i = pointer; buffer[i]; i++){
    // concatenate and covert ascii to char
    string += String.fromCharCode(buffer[i]) 
  }

//Run helloworld from webassembly
  document.getElementById('container').textContent = string
})()