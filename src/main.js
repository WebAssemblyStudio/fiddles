(async()=>{
const codePromise = fetch('../out/main.wasm')
const module = await WebAssembly.instantiateStreaming(codePromise)

})