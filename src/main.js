(async() => {
  const codePromise = fetch('../out/main.wasm')
  const modele = await WebAssembly.instantiateStreaming(codePromise)
  console.log(module)
})