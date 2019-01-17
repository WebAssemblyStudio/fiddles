const memory = new WebAssembly.Memory({initial:10, maximum:100});

fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  instance = results.instance;

  inputArray = [12, 13, 8, 3, 29];
  const i32 = new Int32Array(memory.buffer);
  i32.set(inputArray);
  outArray = instance.exports.test(i32, 0, 4);
  
  document.getElementById("container").textContent = outArray;
}).catch(console.error);
