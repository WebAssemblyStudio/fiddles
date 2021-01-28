(async () => {
  const obj = await WebAssembly.instantiateStreaming(fetch('mylib.wasm'));
  var resultJS = test(getLastPrime);
  console.log(`Last Prime number (JS)  : ${resultJS.number}, time:  ${resultJS.time} ms`);
  var resultWASM = test(obj.instance.exports.getLastPrime);
  console.log(`Last Prime number (WASM): ${resultWASM.number}, time:  ${resultWASM.time} ms`);  
  console.log("-------------------------------------------------")
})();

function isPrime(number) {
	if (number < 2) return false;
	for (let i = 2; i < number; i++)
		if (number%i == 0) return false;

	return true;	
}

function getLastPrime(number) {
	var lastPrime = 2;
	for (let i = 2; i <= number; i++)
		if (isPrime(i)) lastPrime = i;

	return lastPrime;
}

function test(func) {
  const numberTest = 50000;
  var startTime = new Date().getTime();  
  var lastPrime = func(numberTest);
  return {number: lastPrime, time: new Date().getTime()-startTime};
}


