const x = '../out/main.wasm';

fetch(x).then(response =>
  response.arrayBuffer()
).then(bytes =>
  WebAssembly.instantiate(bytes)
).then(results => {
  const instance = results.instance;
  const f = instance.exports.multiply;
  var s2 = 0;
  console.time('multiply using operator');
  for (var i = 0; i < 10000; i++) {
    for (var j = 0; j < 10000; j++) {
      s2 += i*j;
    }
  }
  console.timeEnd('multiply using operator');
  var s1 = 0;
  console.time('multiply using webassembly');
  for (var i = 0; i < 10000; i++) {
    for (var j = 0; j < 10000; j++) {
      s1 += f(i, j);
    }
  }
  console.timeEnd('multiply using webassembly');
  //document.getElementById("container").textContent = s1 + ' ' + s2;
  console.assert(s1 === s2);
}).catch(console.error);
