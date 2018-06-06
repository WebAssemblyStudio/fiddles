



fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  instance = results.instance;
  document.getElementById("container").innerText = getRange().join("_");
}).catch(console.error);


function getRange() {
  const data = [1, -3, 5, 10, 4];

  const array = new Float32Array(data.length);

  for (let i=0; i<data.length; ++i) {
      array[i] = data[i];
  }

  const buffer = Module._malloc(array.length * array.BYTES_PER_ELEMENT);

  Module.HEAPF32.set(array, buffer >> 2)

  const rangePtr = Module.ccall("main", null, ["number", "number"], [buffer, data.length]);

  const range = [];
  range[0] = Module.HEAPF32[result/Float32Array.BYTES_PER_ELEMENT];
  range[1] = Module.HEAPF32[result/Float32Array.BYTES_PER_ELEMENT + 1];

 Module._free(buffer)

}