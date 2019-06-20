fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes , { env: { error: console.warn.bind(console) }})).then(results => {
  const instance = results.instance;
  const mem = instance.exports.memory;
  console.log(Object.keys(instance.exports).length, Object.keys(instance.exports).join(", "));
  const F32 = new Float32Array(mem.buffer);
  const I32 = new Int32Array(mem.buffer);
  const a = instance.exports.vec2(0,Math.PI/2);
  const b = instance.exports.vec2(10,20);
  const v = instance.exports.vec4vv(a,instance.exports.vec2_cos(a));
  const w2 = instance.exports.vec2_mod(instance.exports.vec2(26.2,-36.2), instance.exports.vec2n(2));

  document.getElementById("container").textContent = `${F32.slice(w2>>2, (w2+8)>>2)}`;
}).catch(console.error);
