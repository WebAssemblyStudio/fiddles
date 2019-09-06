let memory;
function array2Buffer(memory, array, offset) {
  const shared = new Uint32Array(memory.buffer, offset, array.length);
  array.forEach((c, i) => shared[i] = c);
}

function getRandomArray(n) {
  const arr = [];
  while(n--) arr.push(Math.round(Math.random() * n));
  return arr;
}

fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes, {
   env: {
    println(offset, len) {
      let shared = new Uint32Array(memory.buffer, offset, len);
      console.log(`[After Sort]: ${shared}`);
    }
  }
})).then(ret => {
   const exports = ret.instance.exports;
  memory = exports.memory;
  const arr = getRandomArray(10);
  console.log(`[Before Sort]: ${arr}`);
  array2Buffer(memory, arr, exports.getArrayOffset());
  
  const startTime = performance.now();
  exports.sort();
  const endTime = performance.now();
  console.log(`done in ${endTime - startTime}ms.`);
}).catch(console.error);





