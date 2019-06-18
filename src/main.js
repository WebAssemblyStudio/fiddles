fetch('../out/main.wasm').then(response => response.arrayBuffer()).then(bytes => WebAssembly.instantiate(bytes)).then(results => {instance = results.instance;

var loopCount =200000000;

var t0 = performance.now();
for (var i=0 ; i <loopCount; i++) {
    Math.sqrt(i);
}
var t1 = performance.now();
console.log("JavaScript loop took " + (t1 - t0) + " milliseconds.")

var t0 = performance.now();
instance.exports.main(loopCount);
var t1 = performance.now();
console.log("WASM loop took " + (t1 - t0) + " milliseconds.")


}).catch(console.error);
