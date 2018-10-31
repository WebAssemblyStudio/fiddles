// https://www.youtube.com/watch?v=yEYtwmI7bDg&t=191s

function my(wasm) {
  const textAsBytes = new Uint8Array(wasm.exports.memory.buffer, wasm.exports.position, wasm.exports.length);
  const textAsString = new TextDecoder('utf8').decode(textAsBytes);
  console.log("bls ", wasm);
  document.getElementById("container2").textContent = textAsString;
}

fetch("../out/my.wasm").then(response =>
  response.arrayBuffer()
).then(bytes =>
  WebAssembly.instantiate(bytes, {})
).then(result =>
  result.instance
).then(my);