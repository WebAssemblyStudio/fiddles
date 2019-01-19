function fibonacci(sequenceFor) {
  if (sequenceFor <= 1) return 1;
  return fibonacci(sequenceFor - 1) + fibonacci(sequenceFor - 2);
}

WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  env: {
    abort(msg, file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  },
}).then(result => {
  const exports = result.instance.exports;
  let beganAt;
  let fib45;
  let totalAsElapsed = 0;
  let totalJsElapsed = 0;
  
  for (let i = 1, n = 500; i<=n; i++) {
	  beganAt = new Date().getTime();
	  fib45 = exports.fibonacci(30);
	  totalAsElapsed += ((new Date().getTime() - beganAt) / 1000);
	  
	  beganAt = new Date().getTime();
	  fib45 = fibonacci(30);
	  totalJsElapsed += ((new Date().getTime() - beganAt) / 1000);
	  
	  if (!(i%50)) console.log(i, 'of ', n, 'iterations....');
  }
  
  console.log('totalAsElapsed', totalAsElapsed);
  console.log('totalJsElapsed', totalJsElapsed);
  let asElapsedGainPct = ((totalJsElapsed/totalAsElapsed) - 1) * 100;
console.log('asElapsedGain (%)', asElapsedGainPct);
}).catch(console.error);
