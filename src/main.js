fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  instance = results.instance;
  
  return instance;
}).then(instance => {
  const result = measurePerf(() => instance.exports.fibonacci(42), 10);
  document.getElementById("container").innerHTML += `<p>${result}</p>`;
}).then(() => {
  const result = measurePerf(() => fib(42), 10);
  document.getElementById("container").innerHTML += `<p>${result}</p>`;
});

const fib_rec = n => {
  if (n <= 0) {
    throw new Error('n must not be less or equal to zero');
  }
  switch(n) {
    case 1:
    case 2:
      return 1;
    case 3:
      return 2;
    default:
      return fib_rec(n-1) + fib_rec(n-2);
  }
}

const fib = n => {
  if (n <= 0) {
		throw new Error('n must not be less or equal to zero');
	} else if (n === 1) {
		return 1;
	}
	let i = 0;
	let sum = 0;
	let last = 0;
	let curr = 1;
	while (i < n - 1) {
		sum = last + curr;
		last = curr;
		curr = sum;
		i += 1;
	}
	return sum;
}

const measurePerf = (f, n) => {
  let i = -1;
  const start = performance.now();
  let value;
  while(++i < n) {
    value = f();
  }
  const end = performance.now();
  return `total: ${(end-start).toFixed(3)}ms, mean: ${((end-start)/n).toFixed(3)}ms, value: ${value}`;
}