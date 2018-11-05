const { includes } = wasm_bindgen;
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
const run = ()=> {
  let total  =0;
  for(let i =0; i< 10; i++){
  wasmTime = performance.now();
  includes("helloWorld", "hello");
  wasmTime = performance.now() - wasmTime;
  total = total + wasmTime;
  }
  chartOptions.data[0].dataPoints[0].y = total/10;
  chart.render();


 total  =0;
  for(let i =0; i< 10; i++){
jsTime = performance.now();
"helloWorld".includes("hello");
jsTime = performance.now() - jsTime;
total = total + jsTime;
  }
chartOptions.data[0].dataPoints[1].y = total/10;
chart.render();
};

wasm_bindgen('../out/main.wasm').then(() => run());

