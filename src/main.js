var mylib = null;
(async () => {
  const fetchPromise = fetch('../out/mylib.wasm');
  const obj = await WebAssembly.instantiateStreaming(fetchPromise);
  mylib = obj.instance.exports;
  test(true); // JS
  test(false); // WASM
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
	for (let i = 2; i <= number; i++) {
		if (isPrime(i))
			lastPrime = i;
	}
	return lastPrime;
}

function test(isJS) {
  const numberTest = 50000;
  var startTime = new Date().getTime();
  if (isJS)
    console.log(`Last Prime number (JS)  : ${getLastPrime(numberTest)}, time:  ${new Date().getTime()-startTime} ms`);
  else
    console.log(`Last Prime number (WASM): ${mylib.getLastPrime(numberTest)}, time:  ${new Date().getTime()-startTime} ms`);  
}



