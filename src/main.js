const singleArgMathFuncs = ['acos', 'acosh', 'asin', 'asinh', 'atan', 'atanh', 'cos', 'cosh', 'erf', 'erfc', 'exp', 'log', 'logb', 'sin', 'sinh', 'tan', 'tanh'];
const base_env = {
	atan2: (a, b) => Math.atan2(a, b),
	fmax: (a, b) => Math.max(a, b),
	hypot: (a, b) => Math.hypot(a, b),
	pow: (a, b) => Math.pow(a, b)
};
singleArgMathFuncs.forEach(name => {
	base_env[name] = new Function('x', `return Math.${name}(x)`);
})
Object.keys(base_env).forEach(name => {
	// The f32 variants have the same implementation as the f64 variants.
	base_env[`${name}f`] = base_env[name];
})

async function getrt() {
  const rtdata = await fetch("../out/rt.wasm");
  const rtbuf = await rtdata.arrayBuffer();
  const rt = WebAssembly.instantiate(rtbuf, {
    env: base_env
  });
  return rt;
}

getrt().then(function(rt) {
  const rt_instance = rt["instance"];
  const rt_module = rt["module"];
  const rt_exports = rt_instance.exports;
      console.log(Object.keys(rt_exports));
  fetch("../out/main.wasm")
    .then(response => response.arrayBuffer())
    .then(bytes => WebAssembly.instantiate(bytes, { env: rt_exports }))
    .then(results => {
      instance = results.instance;
      document.getElementById("container").innerText = instance.exports.Main(
        3
      );
    });
});
