fetch('../out/main.wasm').then(response => response.arrayBuffer()).then(bytes => WebAssembly.instantiate(bytes)).then(wasm => {
  var js = this;
  var wa = wasm.instance.exports;
  
  compare(
    js.process,
    wa.process,
    20);

}).catch(console.error);

function fib(n) {
  if (n == 0) return 0;
  if (n == 1) return 1;
  return fib(n-1) + fib(n-2);
}

function process(n) {
  var res = fib(n);
  return res;
}





















function compare(fn1, fn2, arg) {
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

  var output = '';
  output += '<tr><td>#1</td><td>' + duration1 + '</td><td>' + result1 + '</td></tr>';
  output += '<tr><td>#2</td><td>' + duration2 + '</td><td>' + result2 + '</td></tr>';
  output += '<tr><td></td><td style="font-size:90%"><b>' + Math.round((duration1/ duration2) * 100) / 100 + ' x faster</b></td><td></td></tr>';
  document.getElementById("container").innerHTML = output;
}
