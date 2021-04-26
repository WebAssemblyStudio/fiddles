fetch("../out/main.wasm")
  .then((response) => response.arrayBuffer())
  .then((bytes) => WebAssembly.instantiate(bytes))
  .then(({ instance }) => {
      const result = instance.exports.vec2(10.65, 0.5);
      console.log({ result });
  })
  .catch(console.error);
