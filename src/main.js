
const initial = 2048 * Float32Array.BYTES_PER_ELEMENT * 2;
const memory = new WebAssembly.Memory({ initial });
const memoryBuffer = new Float32Array(memory.buffer);
for(let i=0;i<2048;++i){
  memoryBuffer[i]=Math.sin(i/2000)*100;
  memoryBuffer[2048+i]=Math.sin(i/2000)*100;
}

WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  main: {
    sayHello() {
      console.log("Hello from WebAssembly!");
    }
  },
  env: {
    memory,
    abort(_msg, _file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    },
    trace(_msg, a0,a1,a2,a3){
console.log(_msg, a0,a1,a2,a3);
    }
  },
}).then(result => {
  const exports = result.instance.exports;
  document.getElementById("container").textContent = "Result: " + exports.InitGainAnalysis(44100);

  document.getElementById("container").textContent += "Result: " + exports.AnalyzeSamples(0, 2048);
  document.getElementById("container").textContent += "Get: " + exports.get(0);
  document.getElementById("container").textContent += "Get: " + exports.get(1);
  document.getElementById("container").textContent += "Get: " + exports.get(2);
  document.getElementById("container").textContent += "Result: " + exports.AnalyzeSamples(0, 2048);
  exports.AnalyzeSamples(0, 2048);
  exports.AnalyzeSamples(0, 2048);
  exports.AnalyzeSamples(0, 2048);
  exports.AnalyzeSamples(0, 2048);
  exports.AnalyzeSamples(0, 2048);
  exports.AnalyzeSamples(0, 2048);
  exports.AnalyzeSamples(0, 2048);
  exports.AnalyzeSamples(0, 2048);
  exports.AnalyzeSamples(0, 2048);
  exports.AnalyzeSamples(0, 2048);
  exports.AnalyzeSamples(0, 2048);
  exports.AnalyzeSamples(0, 2048);
  document.getElementById("container").textContent += "Result: " + exports.GetTitleGain();
}).catch(console.error);
