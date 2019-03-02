var importObject = {
		env: {
			memory: new WebAssembly.Memory({ initial: 1 })
		}
};

var wasmMemoryF64Array = new Float64Array(importObject.env.memory.buffer);

let array = [0, 10, 20, 30, 40, 50, 60, 70, 80, 90];

array.forEach((element, idx) =>
		wasmMemoryF64Array[idx] = element);

fetch('../out/binarySearch.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes, importObject)).then(results => {
  let instance = results.instance;
  let binarySearch = instance.exports.binarySearch;
  let result = binarySearch(array.length - 1, 30);

  document.getElementById("container").textContent = result;
}).catch(console.error);

