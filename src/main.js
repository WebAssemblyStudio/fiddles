fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  instance = results.instance;
  var t0 = performance.now()
  document.getElementById("container").textContent = instance.exports.add(105,41);
  var t1 = performance.now()
  console.log("Call to doSomething took " + (t1 - t0) + " milliseconds.") //function that display value
}).catch(console.error);
