async function getrt() {
  const rtdata = await fetch("../out/rt.wasm");
  const rtbuf = await rtdata.arrayBuffer();
  const rt = WebAssembly.instantiate(rtbuf, {
    env: {
      sin: function(x) {
        return Math.sin(x);
      }
    }
  });
  return rt;
}

getrt().then(function(rt) {
  const rt_instance = rt["instance"];
  const rt_module = rt["module"];
  const rt_exports = rt_instance.exports;
  console.log(rt_instance);
  fetch("../out/main.wasm")
    .then(response => response.arrayBuffer())
    .then(bytes => WebAssembly.instantiate(bytes, { env: rt_exports }))
    .then(results => {
      instance = results.instance;
      document.getElementById("container").innerText = instance.exports.add_two(
        3
      );
    });
});
