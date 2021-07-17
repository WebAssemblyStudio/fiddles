// Load WebAssembly module
window.results = await WebAssembly.instantiateStreaming( fetch('../out/main.wasm') ).catch(console.error)
window.instance = results.instance
window.exports = instance.exports

window.container = document.querySelector("#result")
window.container.innerHTML = exports.add(12,1)





const wasmFile = document.querySelector('#wasmFile')
const wasmBlob = await (await fetch(wasmFile.href)).blob()
wasmFile.href = URL.createObjectURL(wasmBlob)




// Load StyleSheet
const myStyleSheet = new CSSStyleSheet
await myStyleSheet.replace( await (await fetch('main.css')).text() )

document.adoptedStyleSheets = [myStyleSheet]
