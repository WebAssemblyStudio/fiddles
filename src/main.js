// Load WebAssembly module
window.results = await WebAssembly.instantiateStreaming( fetch('../out/main.wasm'),
{ 
  js: {
    global: 10
  },

  console: {
    log: console.log
  } 
})
.catch(console.error)

window.instance = results.instance
window.exports = instance.exports

window.container = document.querySelector("#result")



//exports.setGlobal(33)
//window.container.innerHTML = exports.getGlobal()


//window.container.innerHTML = exports.add(10, 1)


//window.container.innerHTML = exports.testIf(10)



// Put download link of the wasm file
const wasmFile = document.querySelector('#wasmFile')
const wasmBlob = await (await fetch(wasmFile.href)).blob()
wasmFile.href = URL.createObjectURL(wasmBlob)




// Load StyleSheet
const myStyleSheet = new CSSStyleSheet
await myStyleSheet.replace( await (await fetch('main.css')).text() )

document.adoptedStyleSheets = [myStyleSheet]
