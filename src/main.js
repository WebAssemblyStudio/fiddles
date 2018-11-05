const CanvasJS = require('canvasjs');
let wasmTime = 0, jsTime = 0;
const chart = new CanvasJS.Chart("chartContainer", {
	animationEnabled: true,
	theme: "light2",
	title:{
		text: "Perf"
	},
	axisY: {
		title: "ms"
	},
	data: [{        
		type: "column",  
		showInLegend: true, 
		legendMarkerColor: "grey",
		dataPoints: [      
			{ y: wasmTime, label: "Wasm" },
			{ y: jsTime,  label: "Js" },
		]
	}]
});
fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  instance = results.instance;
  wasmTime = performance.now();
  const result  = instance.exports.fib(41);
  wasmTime = performance.now() - wasmTime;
  document.getElementById("wasm").textContent = result;
  chart.render();
}).catch(console.error);

function fibonacci(num) {
  if (num <= 1) return 1;
  return fibonacci(num - 1) + fibonacci(num - 2);
}

jsTime = performance.now();
const result = fibonacci(40);
jsTime = performance.now() - jsTime;
document.getElementById("js").textContent = result;
chart.render();


