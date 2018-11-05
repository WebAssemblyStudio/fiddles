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
  const result  = instance.exports.fib(10000);
  wasmTime = performance.now() - wasmTime;
  chartOptions.data[0].dataPoints[0].y = wasmTime;
  chart.render();
}).catch(console.error);

function fibonacci(num){
  var a = 1, b = 0, temp;

  while (num >= 0){
    temp = a;
    a = a + b;
    b = temp;
    num--;
  }

  return b;
}

jsTime = performance.now();
fibonacci(9999);
jsTime = performance.now() - jsTime;
chartOptions.data[0].dataPoints[1].y = jsTime;
chart.render();


