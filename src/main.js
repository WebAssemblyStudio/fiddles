let samples = [];


WebAssembly.instantiateStreaming(fetch('../out/main.wasm'), {}).then(results => {

  instance = results.instance;
  instance.exports.memory.grow(1024 * 2);
 
  let data_ptr = instance.exports.getDataPointer();
  let data = new Uint32Array(instance.exports.memory.buffer, data_ptr, 256 * 256 * 256);

  setInterval(() => {
		
    let timestamp = performance.now();
  
    data[0] = 1;
    
    instance.exports.shift(data_ptr, 1, 0, 0);

    samples.push(performance.now() - timestamp);

		if (samples.length > 100) samples.shift();

		let sum = samples.reduce((acc, val) => acc + val);

    document.getElementById("container").innerHTML = `<pre>
      shift ${(sum / samples.length / 10).toFixed(2)} ms
      data[2] = ${data[1]}
    </pre>`;

  }, 1000);    

  console.log(data[0]);

  
})