let e = {
  env: {
    console_log: function(n) {
      console.log(n);
    }
  }
}

fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes, e)).then(results => {
  instance = results.instance;
  document.getElementById("container").textContent = instance.exports.test("test");
}).catch(console.error);
