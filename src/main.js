var t0 = performance.now();
fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  instance = results.instance;
  document.getElementById("container").textContent = instance.exports.add_one();
}).catch(console.error);

var t1 = performance.now()
            console.log("Call to doSomething took " + (t1 - t0) + " milliseconds.")
            console.log(result)
