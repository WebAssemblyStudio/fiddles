let samples = [];


WebAssembly.instantiateStreaming(fetch('../out/main.wasm'), {}).then(results => {

  instance = results.instance;
  instance.exports.memory.grow(1024);
  
  let data = new Uint32Array(instance.exports.memory.buffer);

  //document.getElementById("container").textContent = 
  
  setInterval(() => {
		
    let timestamp = performance.now();
    
    instance.exports.test();

    samples.push(performance.now() - timestamp);

		if (samples.length > 100) samples.shift();

		let sum = samples.reduce((acc, val) => acc + val);

    document.getElementById("container").innerHTML = `<pre>
      forward_test ${(sum / samples.length / 10).toFixed(2)} ms
      data[2] = ${data[2]}
    </pre>`;

  }, 100);
  
  

  console.log(data[0]);

  
})