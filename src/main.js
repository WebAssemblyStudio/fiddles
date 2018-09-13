fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  instance = results.instance;
  var base = instance.exports.__heap_base;
  var memory = instance.exports.memory;
  const ns = 16;
  var numNeeded = 2*ns*8;
  if (memory.buffer.byteLength - base < numNeeded) {
    var additionalNeeded = numNeeded - (memory.buffer.byteLength - base);
    memory.grow(Math.floor((additionalNeeded + 65535) / 65536));
  }
  var floats = new Float32Array(memory.buffer, base, 2*2*ns);
  for (var i = 0; i < ns; ++i) {
    var o = i * 2;
    floats[o] = 1 - (i & (ns >> 3)) / (ns >> 3);
    floats[o + 1] = 0;
    o += ns;
    floats[o] = 1;
    floats[o + 1] = 0;
  }
  const sm = (f) => Math.round(f * 1.0e4) * 1.0e-4;
  const ff = (f) => {
    var s = f.toString();
    var p = s.indexOf(".");
    return s.substring(0, p + 5);
  };
  const cmp = (arr) => {
    var result = [];
    for (var i = 0; i < arr.length; i += 2) {
      var re = sm(arr[i]);
      var im = sm(arr[i + 1]);
      if (im != 0) {
        var sc = [];
        if (re != 0) {
          sc.push(re);
          if (im >= 0) sc.push("+");
        }
        sc.push(im, "i");
        result.push(sc.map(ff).join(""));
      } else {
        result.push(ff(re));
      }
    }
    return result.join(", ");
  }
  console.log("1o: "+cmp(floats.slice(0, ns * 2)));
  console.log("2o: "+cmp(floats.slice(ns * 2)));
  instance.exports.multidfft(floats.byteOffset, ns, 1, 2);
  console.log("1f: "+cmp(floats.slice(0, ns * 2)));
  console.log("2f: "+cmp(floats.slice(ns * 2)));
  instance.exports.multidfft(floats.byteOffset, ns, -1, 2);
  const invns = 1/ns;
  for (var i = 0; i < 4*ns; ++i) {
    floats[i] *= invns;
  }
  console.log("1i: "+cmp(floats.slice(0, ns * 2)));
  console.log("2i: "+cmp(floats.slice(ns * 2)));
  console.log("");
  // document.getElementById("container").innerText = instance.exports.main();
}).catch(console.error);
