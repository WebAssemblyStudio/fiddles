function fn(name) {
  return function () {
    console.log("CALL %s [%d]", name, arguments.length, ...arguments);
  }
}

fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes, {
  env: new Proxy({}, {
    get(_, name) {
      console.log("GET %s", name);
      return fn(name);
    }
  })
})).then(results => {
  instance = results.instance;
  document.getElementById("container").textContent = instance.exports.main();
}).catch(console.error);
