fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  instance = results.instance;

  const buffer = instance.exports.memory.buffer
  const arr = new Int32Array(buffer, 0, 10)
  for (let i = 0; i < arr.length; i++) {
    arr[i] = i + 1
  }
  console.log(arr.length)

  document.getElementById("container").textContent = instance.exports.sum(arr.byteOffset, arr.length);
}).catch(console.error);
