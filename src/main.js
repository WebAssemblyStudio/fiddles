const decoder = new TextDecoder('utf-8')
const encoder = new TextEncoder('utf-8')

fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  const app = results.instance.exports;
  const wafflesPtr = init_string(app, 'waffles')
  console.log(wafflesPtr)
  const helloPtr = init_string(app, 'hello')
  console.log(helloPtr)

  //document.getElementById("container").textContent = read_string(app, wafflesPtr);
  console.log(read_string(app, wafflesPtr))
//  console.log(read_string(app, helloPtr))
  app.reset() // new allocations will overwrite memory now
  // const worldPtr = init_string(app, 'world')
  // console.log(read_string(app, worldPtr))
  // console.log(read_string(app, wafflesPtr))
  
}).catch(console.error);

function init_string(app, s) {
  const bytes = encoder.encode(s)
  let _ptr = app.allocate(bytes.byteLength + 4)
  let ptr = _ptr
  const view = new DataView(app.memory.buffer)
  view.setUint32(_ptr, bytes.byteLength, true) // length-prefixed strings
  _ptr += 4
  for (let i = 0; i < bytes.byteLength; i++) {
    view.setUint8(_ptr, bytes[i])
    _ptr++
  }
  return ptr
}

function read_string(app, ptr) {
  const view = new DataView(app.memory.buffer, ptr, 4)
  const length = view.getUint32(0, true)
  const bytes = new DataView(app.memory.buffer, ptr + 4, length)
  return decoder.decode(bytes)
}
