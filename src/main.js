
function finish(code) {
  // Use JS exception to implement "noreturn" finish() function.
  throw code
}

var importObject = { eei: { finish: finish } };

WebAssembly.instantiateStreaming(fetch('../out/main.wasm'), importObject).then(o => {
  try {
    // Use the returned value when main() returns normally.
    r = o.instance.exports.main();
  } catch(code) {
    // Use the value from the exception when main() uses finish().
    r = code
  }  
  document.getElementById("container").innerText = r
}).catch(console.error);

