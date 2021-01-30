(async() => {
  const codePromise = fetch('../out/main.wasm'); // fetch main.wasm, present when we build the code
  const {instance} = await WebAssembly.instantiateStreaming(codePromise); // recommended way by mozilla
  
  const buffer = new Uint8Array(instance.exports.memory.buffer); // Array with values [123456, 654321, 'H', 'E', ... ]
  const pointer = instance.exports.helloWorld();
  let string = '';
  for (let i = pointer; buffer[i]; i++) {
    // console.log(buffer[i])
    string += String.fromCharCode(buffer[i])
  }
  document.getElementById('container').textContent = string
})()

// fetch('../out/main.wasm').then(response =>
//   response.arrayBuffer()
// ).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
//   instance = results.instance;
//   document.getElementById("container").textContent = instance.exports.main();
// }).catch(console.error);
