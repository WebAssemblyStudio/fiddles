const imports = {
    env: {
        setText: (x) =>  document.getElementById("container").textContent = x
    }
}

fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes, imports)).then(results => {
  instance = results.instance;
  document.getElementById('click').addEventListener('click', () => {
    instance.exports.onClick();
  });
}).catch(console.error);
