WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  env: {
    seed: Date.now,
    abort(_msg, _file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  },
}).then(result => {
  const exports = result.instance.exports;

  // init
  exports.createPoints();

  const printType = (x, y) => `[${x}, ${y}] = 0x${(exports.getClosestNeighbourType(0, 0) >>> 0).toString(16)}`;

  const results = [
    printType(0, 0),
    printType(1, 2),
    printType(128, -128),
    printType(512, -512),
  ].join(',<br/>');

  document.getElementById("container").innerHTML = "minDistanceTypes:<br/><br/>" + results;
}).catch(console.error);
