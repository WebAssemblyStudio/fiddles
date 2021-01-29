var mylib = null;
var testNumber = 1;
document.querySelector("#primeJS").innerHTML = "Starting...";
var interval = setInterval(function() {
	(async () => {
	  if (!mylib) {
		  mylib = await WebAssembly.instantiateStreaming(fetch('mylib.wasm'));
      document.querySelector("#primeJS").innerHTML = "";
    }

    var resultJS = test(getSumPrime);
    document.querySelector("#primeJS").innerHTML += `${testNumber}. Sum Prime number (JS): ${resultJS.number}, time:  ${resultJS.time} ms<br>`;
    var resultWASM = test(mylib.instance.exports.getSumPrime);
    document.querySelector("#primeWASM").innerHTML += `${testNumber}. Sum Prime number (WASM): ${resultWASM.number}, time:  ${resultWASM.time} ms<br>`;  
    if (testNumber >= 10)
      clearInterval(interval);

    testNumber++;
	})();
},1000);

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


