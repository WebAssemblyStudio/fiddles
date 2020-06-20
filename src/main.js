fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  var wasm = results.instance.exports;
  var output = test(fib, wasm.fib, 35);
  document.getElementById("container").innerHTML = output;
}).catch(console.error);

function fib_impl(n) {
  if (n == 0) return 0;
  if (n == 1) return 1;
  return fib_impl(n-1) + fib_impl(n-2);
}

function fib(n) {
  var res = fib_impl(n);
  return 0;
}
















function test(fn1, fn2, arg) {
  result1 = '';
  start1 = performance.now();
  for (i = 0; i<= arg; i++) {
    result1 += fn1(i) + ',';
  }
  //result1 += fn1(arg);
  duration1 = (Math.round((performance.now() - start1) * 1000) / 1000);

  result2 = '';
  start2 = performance.now();
  for (i = 0; i<= arg; i++) {
    result2 += fn2(i) + ',';
  }
  //result2 += fn2(arg);
  duration2 = (Math.round((performance.now() - start2) * 1000) / 1000);

  var retVal = '';
  retVal += '<tr><td>#1</td><td>' + duration1 + '</td><td>' + result1 + '</td></tr>';
  retVal += '<tr><td>#2</td><td>' + duration2 + '</td><td>' + result2 + '</td></tr>';
  retVal += '<tr><td></td><td>' + Math.round((duration1/ duration2) * 100) / 100 + ' x faster</td><td></td></tr>';
  return retVal;
}
