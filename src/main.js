let wasmTime = 0, jsTime = 0;
const chartOptions = {
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
			{ y: 0, label: "Wasm" },
			{ y: 0,  label: "Js" },
		]
	}]
};
const chart = new CanvasJS.Chart("chartContainer", chartOptions);
fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  instance = results.instance;
  wasmTime = performance.now();
  const result  = instance.exports.fib(41);
  wasmTime = performance.now() - wasmTime;
  document.getElementById("wasm").textContent = result;
  chartOptions.data[0].dataPoints[0].y = wasmTime;
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
chartOptions.data[0].dataPoints[1].y = jsTime;
chart.render();


