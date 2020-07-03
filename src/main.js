fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  instance = results.instance;
  const add_one = instance.exports.add_one;
  const hello_world = instance.exports.hello_world;

  alert(hello_world());

  document.querySelector('#c').addEventListener('click', () => {
    document.getElementById("container").textContent = add_one(41);
  })
}).catch(console.error);
