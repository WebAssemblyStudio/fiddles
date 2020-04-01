let x = '../out/main.wasm';

let s = "";
fetch(x).then(response =>
  response.arrayBuffer()
).then(bytes => {
  const base64 = btoa(String.fromCharCode.apply(null, new Uint8Array(bytes)));
  document.getElementById("container").insertAdjacentHTML(
    "beforeend",
    "<pre>" + base64 + "</pre>"
  );
  return WebAssembly.instantiate(bytes)
}).then(results => {
  instance = results.instance;
  document.getElementById("container").insertAdjacentHTML(
    "beforeend",
    "<pre>" + instance.exports.noise2D(0.4, 0.8) + "</pre>"
  );
}).catch(console.error);
