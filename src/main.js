(async () => {
const codeProimse = fetch('../out/main.wasm')
const { instance } = await WebAssembly.instantiateStreaming(codeProimse)
const buffer = new Unit8Array(instance.exports.memory.buffer) //array
const pointer = instance.exports.demoPrinting() //Location of my message


let stringMessage=""
for(let i = pointer; buffer[i]; i++ ){
stringMessage += String.fromCharCode(buffer[i]) //conver my message into String
}
document.getElementById('container').textContent = stringMessage
})()
