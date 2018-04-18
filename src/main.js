WebAssembly.instantiateStreaming(
  fetch('../out/main.wasm')
  .then(obj => {
    const answer = obj.instance.exports.add(20,22);
    console.log(answer);
  })
);