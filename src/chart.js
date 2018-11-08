

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

const runWasmFnNTimes = (n) => (func)=> {
let total=0;
for(let i =0; i< n; i++){
time = performance.now();
func();
time = performance.now() - time;
total = total + time;
}
chartOptions.data[0].dataPoints[0].y = total/n;
chart.render();
};

const runWasmFnOneTime = runWasmFnNTimes(1);
const runWasmFn100Times = runWasmFnNTimes(100);

const runJsFnNTimes = (n)=> (func)=> {
let total=0;
for(let i =0; i< n; i++){
jsTime = performance.now();
func();
jsTime = performance.now() - jsTime;
total = total + jsTime;
}
chartOptions.data[0].dataPoints[1].y = total/n;
chart.render();
};
const runJsFnOneTime = runJsFnNTimes(1);
const runJsFn100Times = runJsFnNTimes(100);