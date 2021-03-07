const options = {
  imports: {
     print: (e) => console.log(e)
  }
};

fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes, options)).then(results => {
  instance = results.instance;
  instance.exports.helloworld("hello".toString(2));
  document.getElementById("container").textContent = instance.exports.minus1(30) 
}).catch(console.error);

