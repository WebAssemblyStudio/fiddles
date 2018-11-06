

let wasmTime = 0, jsTime = 0;
const chartOptions = {
	animationEnabled: true,
	theme: "light2",
	title:{
		text: "Perf"
	},
	axisY: {
    minimum: 0.00001,
    maximum: 0.1,
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

const runWasmFn100Times = (func)=> {
let total=0;
for(let i =0; i< 100; i++){
time = performance.now();
func();
time = performance.now() - time;
total = total + time;
}
chartOptions.data[0].dataPoints[0].y = total/10;
chart.render();
};

const runJsFn100Times = (func)=> {
let total=0;
for(let i =0; i< 100; i++){
jsTime = performance.now();
func();
jsTime = performance.now() - jsTime;
total = total + jsTime;
}
chartOptions.data[0].dataPoints[1].y = total/10;
chart.render();
};