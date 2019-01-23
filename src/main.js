
function leibnizPow(i) {
  return Math.pow(-1, i) / (2 * i + 1);
}

function leibniz(n) {
  var r = 0;
  for (var i = 0; i < n; i++) {
    r += leibnizPow(i);
  }
  return 4 * r;
}

fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  const exports = results.instance.exports;

  console.time('leibniz.js');
  const rjs = leibniz(parseInt(100000000));
  console.timeEnd('leibniz.js');
  console.log('leibniz.js: ' + rjs);

  console.time('leibniz.as');
  const ras = exports.leibniz(parseInt(100000000));
  console.timeEnd('leibniz.as');
  console.log('leibniz.js: ' + ras);

}).catch(console.error);
