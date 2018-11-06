
 function fillArrayWithNumbers(n) {
        var arr = Array.apply(null, Array(n));
        return new Float32Array(arr.map(function (x, i) { return i }));
    }
    const data = fillArrayWithNumbers(1000);
fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  instance = results.instance;

  const nDataBytes = data.length * data.BYTES_PER_ELEMENT;

  const linearMemory = instance.exports.memory;
  const dataHeap = new Uint8Array(linearMemory.buffer, 0, nDataBytes);
  dataHeap.set(new Uint8Array(data.buffer));
  runWasmFnOneTime(()=> instance.exports.sum_of_array(0,nDataBytes));
  
}).catch(console.error);

runJsFnOneTime(()=> data.reduce((sum, value)=> sum + value, 0));


