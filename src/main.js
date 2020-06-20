fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  var wasm = results.instance.exports;
  var output = '';
  var pos = 35;

  // test
  output += test('js rec', pos, fib_rec);
  output += test('js', pos, fib);

  // show results
  document.getElementById("container").innerHTML = output;
}).catch(console.error);

function test(t, n, f) {
  start = performance.now();
  r = f(n);
  d = (Math.round((performance.now() - start) * 1000) / 1000);
  return '<tr><td>' + t + '</td><td>' + r + '</td><td>' + d + ' ms </td></tr>';
}

function fib_rec(n) {
  if (n === 0) return 0;
  if (n === 1) return 1;
  if (n === 2) return 1;
  return fib_rec(n-1) + fib_rec(n-2);
}

function fib(n) {
  let a = 0, b = 1;
  if (n > 0) {
    while (--n) {
      let t = a + b;
      a = b;
      b = t;
    }
    return b;
  }
  return a;
}