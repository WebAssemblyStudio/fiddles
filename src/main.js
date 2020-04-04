let x = '../out/main.wasm';

let instance = null;
let memory = null;

function regressionLib(base64) {
  const that = typeof global === "object" ? global : self;
  const wasm = window.WebAssembly, ABuf = ArrayBuffer, SharedBuf = window.SharedArrayBuffer;
  let wasmInst = null;
  const buffer = wasm ? new wasm.Memory({"initial": 1, "maximum": 16}) : new ArrayBuffer(65504);
    // 65536 - 32 bytes of overhead = 65504
  let viewAsFloat64 = new Float64Array(buffer);

  function maybeGrowBuffer(totalLength) {
    const lenNeeded = totalLength - (viewAsFloat64.length|0) |0;
    if (lenNeeded > 0) {
      if (wasm) {
        buffer.grow((lenNeeded + 8191) >> 13);
      } else {
        viewAsFloat64 = new Float64Array(((totalLength >> 13) + 8191) << 13);
      }
    }
  }

  window["fitRegressionLine"] = function(points, __strat, __max) {
    if (!points || (!points.length && !points.byteLength)) {
      throw Error("Cannot pass a non-array or zero-length-array as the first argument to fitRegressionLine");
    }
    const strateg = __strat|0;
    const maxDegree = typeof __max === "number" && __max > 0 ? __max|0 : 16;
    const maybeBuffer = points.buffer || points;
    const isBuff = maybeBuffer instanceof ABuf || (SharedBuf && maybeBuffer instanceof SharedBuf);
    let lengthOfPoints = 0;
    if (isBuff || typeof points[0] === "number") {
      // YES! Fast numeric array
      const ta = isBuff && maybeBuffer === points ? new Float64Array(points) : points;
      maybeGrowBuffer(maxDegree + ((lengthOfPoints = ta.length|0) << 1) |0);
      viewAsFloat64.set(ta, maxDegree|0);
    } else if ("length" in points) {
      // oh no! slow objects
      const firstPoint = points[0];
      const propX = 0 in firstPoint ? 0 : "X" in firstPoint ? "X" : "x";
      const propY = 1 in firstPoint ? 1 : "Y" in firstPoint ? "Y" : "y";
      const len = points.length|0;
      let bufferIndex = maxDegree - 1|0, pointsIndex = 0;
      let obj = null;
      maybeGrowBuffer(maxDegree + (len << 2) |0);
      for (; pointsIndex < len; pointsIndex = pointsIndex + 1|0)
        if (obj = points[pointsIndex]) {
          viewAsFloat64[bufferIndex = bufferIndex + 1|0] = obj[propX];
          viewAsFloat64[bufferIndex = bufferIndex + 1|0] = obj[propY];
        }
      lengthOfPoints = bufferIndex >> 1;
    } else throw Error("Cannot pass non-array to fitRegressionLine");
    
  };
  if (wasm) {
    const args = {
      "env": {
        "expandMemory": function() {
          memory["grow"](1);
        }
      },
      "js": { "mem": memory }
    };
    let promise;
    if (wasm.instantiateStreaming) {
      promise = wasm.instantiateStreaming("data:application/wasm;base64," + base64, args);
    } else {
      const binString=atob(base64), len=binString.length|0, u8=new Uint8Array(len);
      for (let i=0; i<len; i=i+1|0) {
        u8[i] = binString.charCodeAt(i)|0;
      }
      promise = wasm.instantiate(u8, args);
    }
    promise.then(function(inst) {wasmInst = inst});
  }
}

let asBase64 = "";
fetch(x).then(response => response.arrayBuffer()).then(function(bytes) {
  asBase64 = btoa(String.fromCharCode.apply(null,new Uint8Array(bytes)));
  memory = new WebAssembly;
  
  return WebAssembly.instantiate(bytes, {
    "env": {
      "expandMemory": function() {
        memory["grow"](1);
      }
    },
    "js": { "mem": memory }
  });
}).then(function(__inst) {
  instance = __inst;
  /*document.getElementById("container").insertAdjacentHTML("beforeend",
    "<sect>" + instance.exports.expandMemory() + "</sect>");*/
  document.getElementById("container").insertAdjacentHTML("beforeend","<br /><br />");
  document.getElementById("container").insertAdjacentHTML("beforeend",
    "<sect>" + asBase64 + "</sect>");
}).catch(console.error);
