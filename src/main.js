var mylib = null;
setInterval(function() {
	(async () => {
	  if (!mylib) {
		  document.querySelector("#primeJS").innerHTML = "Reloading...";
		  mylib = await WebAssembly.instantiateStreaming(fetch('mylib.wasm'));
	  }
	  var resultJS = test(getSumPrime);
	  document.querySelector("#primeJS").innerHTML = `Last Prime number (JS)&emsp;&emsp;: ${resultJS.number}, time:  ${resultJS.time} ms`;
	  var resultWASM = test(mylib.instance.exports.getSumPrime);
	  document.querySelector("#primeWASM").innerHTML = `Last Prime number (WASM): ${resultWASM.number}, time:  ${resultWASM.time} ms`;  
	})();
},3000);

function isPrime(number) {
	if (number < 2) return false;
	for (let i = 2; i < number; i++)
		if (number%i == 0) return false;

	return true;	
}

function getSumPrime(number) {
	var sumPrime = 0;
	for (let i = 2; i <= number; i++)
		if (isPrime(i)) sumPrime += i;

	return sumPrime;
}

function test(func) {
  const numberTest = 50000;
  var startTime = new Date().getTime();  
  var lastPrime = func(numberTest);
  return {number: lastPrime, time: new Date().getTime()-startTime};
}


