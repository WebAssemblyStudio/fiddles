
 function fillArrayWithNumbers(n) {
        var arr = Array.apply(null, Array(n));
        return new Float32Array(arr.map(function (x, i) { return i }));
    }
 const data = fillArrayWithNumbers(1000);
fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  instance = results.instance;
  runWasmFn1000Times(()=> instance.exports.sum_of_static_array());
}).catch(console.error);

runJsFn1000Times(()=> data.reduce((sum, value)=> sum + value, 0));


