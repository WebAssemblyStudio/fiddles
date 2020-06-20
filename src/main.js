fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  var wasm = results.instance.exports;
  var output = '';
  var fib_pos = 35;

  // test
  //output += test('js_rec', fib_rec, fib_pos);
  //output += test('ws_rec', wasm.fib_rec, fib_pos);
  //output += test('js', fib, fib_pos);
  //output += test('ws', wasm.fib, fib_pos);

  output += test2('rec', fib_rec, wasm.fib_rec, fib_pos);
  output += test2('non rec', fib, wasm.fib, fib_pos);


  // show results
  document.getElementById("container").innerHTML = output;
}).catch(console.error);

function test2(label, fn1, fn2, arg) {
  result1 = '';
  start1 = performance.now();
  //for (i = 0; i<= arg; i++) {
  //  result1 += fn1(i) + ',';
  //}
  result1 += fn1(arg);
  duration1 = (Math.round((performance.now() - start1) * 1000) / 1000);

  result2 = '';
  start2 = performance.now();
  //for (i = 0; i<= arg; i++) {
  //  result2 += fn2(i) + ',';
  //}
  result2 += fn2(arg);
  duration2 = (Math.round((performance.now() - start2) * 1000) / 1000);

  var retVal = '';
  retVal += '<tr><td>js</td><td>' + duration1 + '</td><td>' + result1 + '</td></tr>';
  retVal += '<tr><td>ws</td><td>' + duration2 + '</td><td>' + result2 + '</td></tr>';
  retVal += '<tr><td></td><td>' + Math.round((duration1/ duration2) * 100) / 100 + '</td><td></td></tr>';
  return retVal;
}

function test(label, fn, arg) {
  start = performance.now();
  result = '';
  for (i = 0; i<= arg; i++) {
    result += fn(i) + ',';
  }
  //result += fn(arg);
  duration = (Math.round((performance.now() - start) * 1000) / 1000);
  return '<tr><td>' + label + '</td><td>' + duration + '</td><td>' + result + '</td></tr>';
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