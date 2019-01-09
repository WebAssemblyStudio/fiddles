async function loadAndInstantiate(url, importObject) {
  const res = await fetch(url);
  const data = await res.arrayBuffer();
  return await WebAssembly.instantiate(data, importObject);
}

(async function() {
  try {
    const myLibModule = await loadAndInstantiate('../out/mylib.wasm'); 
    const mainModule = await loadAndInstantiate('../out/main.wasm', {
      env: {
        isDivisibleByExtern: myLibModule.instance.exports.isDivisibleBy //(a, b) => myLibModule.instance.exports.isDivisibleBy(a, b)
      }
    });
    const startTime = new Date();
    const result = mainModule.instance.exports.computeNthPrime(5000); //20000);
    const duration = new Date().valueOf() - startTime.valueOf();
    document.getElementById("container").textContent = `Result: ${result} in duration ${duration}ms`;
  } catch(ex) {
    alert(ex);
  }
})();