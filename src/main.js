let samples = [];


WebAssembly.instantiateStreaming(fetch('../out/main.wasm'), {}).then(results => {

  instance = results.instance;
  instance.exports.memory.grow(1024 * 2);

  let data = new Uint32Array(instance.exports.memory.buffer, 0, 256 * 256 * 256);
  let temp = new Uint32Array(instance.exports.memory.buffer, 256 * 256 * 256 * 4, 256 * 256 * 256);

  //document.getElementById("container").textContent = 
  
  setInterval(() => {
		
    let timestamp = performance.now();

    instance.exports.shift(0, 256 * 256 * 256, 1, 0, 0);

    samples.push(performance.now() - timestamp);

		if (samples.length > 100) samples.shift();

		let sum = samples.reduce((acc, val) => acc + val);

    document.getElementById("container").innerHTML = `<pre>
      forward_test ${(sum / samples.length).toFixed(2)} ms
      data[2] = ${data[2]}
    </pre>`;

  }, 1000);
  
  

  console.log(data[0]);

  
})