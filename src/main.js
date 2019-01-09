let WASM_PATH = '/out/main.wasm';

var xhr = new XMLHttpRequest;
xhr.open("GET", WASM_PATH, false);
xhr.send();
var wasmCode = xhr.response;
var wasmModule = new WebAssembly.Module(wasmCode);
var wasmInstance = new WebAssembly.Instance(wasmModule, wasmImports);
debugger;
//var memoryArray = 
//log(wasmInstance.exports.main());

const Math_imul = Math.imul;
const map = [
  [0,0,0,0,0,0,0,0],
  [0,0,1,1,1,1,1,0],
  [0,0,1,0,0,0,1,0],
  [0,0,1,0,0,0,1,0],
  [0,0,1,0,0,0,1,0],
  [0,0,0,1,0,0,1,0],
  [0,0,0,1,1,1,1,0],
  [0,0,0,0,0,0,0,1]
];
var mapWidth = map[0].length;
var mapHeight = map.length;
var mapLength = Math_imul(mapWidth, mapHeight);
var heap = new Uint32Array(mapLength * 3);
heap.set(map.flat(), 0);
heap.fill(0, mapLength);
var inst = asmModule(null, n);
inst["init"](mapWidth, mapHeight);
inst["que"](3, 3);
inst["calc"]();
const formatted = [];
function coordToIndex(x, y) {
    return x + Math_imul(y, mapHeight) |0;
}
heap.forEach(function(value, index){
    const pos = indexToCoord(index);
    formatted[pos[1]] = formatted[pos[1]] || [];
    formatted[pos[1]][pos[0]] = value;
});
document.getElementById("container").textContent = "[" + formatted.map(x=> "\t[" + x.join(",\t") + "]").join(",\n") + "\n]";
