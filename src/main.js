fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  instance = results.instance;
  	var start = new Date().getTime();
    document.getElementById("container").textContent = instance.exports.main();
    var end = new Date().getTime();
	  var time = end - start;
	  document.getElementById("timer").textContent = "Execution time: " + time + "ms";

}).catch(console.error);
