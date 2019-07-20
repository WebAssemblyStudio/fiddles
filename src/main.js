(async () => {
  const importObject = {env: {logResult(result){console.log(result);}}}
  const { instance } = await WebAssembly.instantiateStreaming(fetch('../out/main.wasm'), importObject);
  await instance.exports.add_one(41);
})();