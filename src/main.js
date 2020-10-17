let samples = [];


WebAssembly.instantiateStreaming(fetch('../out/main.wasm'), {}).then(results => {

  instance = results.instance;
  instance.exports.memory.grow(1024 * 2);
 
  let data_ptr = instance.exports.getDataPointer();
  let data = new Uint32Array(instance.exports.memory.buffer, data_ptr, 256 * 256 * 256);


  setInterval(() => {
		
    let timestamp = performance.now();
    
    instance.exports.test(data_ptr);

    samples.push(performance.now() - timestamp);

		if (samples.length > 100) samples.shift();

		let sum = samples.reduce((acc, val) => acc + val);

    document.getElementById("container").innerHTML = `<pre>
      forward_test ${(sum / samples.length / 10).toFixed(2)} ms
      data[2] = ${data[2]}
    </pre>`;

  }, 1000);
  
  

  console.log(data[0]);

  
})