fetch('../out/main.wasm').then(response => response.arrayBuffer()).then(bytes => WebAssembly.instantiate(bytes)).then(results => {instance = results.instance;

var loopCount =165536;

//----------------------------

var ta = performance.now();
var a=0;
for (var i=0 ; i <= loopCount; i++) {
    a=a+i;
}
var tb = performance.now();
console.log("JavaScript loop took " + (tb - ta) + " milliseconds." + " ----Result " + a)

//----------------------------

var ta = performance.now();
var ret = instance.exports._Z7newloopi(loopCount);
//var ret = instance.exports.newloop(loopCount);
var tb = performance.now();
console.log("WASM loop took " + (tb - ta) + " milliseconds." + " ----Result " + ret)


});
