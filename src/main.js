
var importObject = {
  imports: {
    say_hello: function() {
      alert("I hope you're enjoying this lunch and learn!");
    }
  }
};

fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes, importObject)).then(results => {
  instance = results.instance;
  document.getElementById("container").textContent = instance.exports.getAnswerPlus1();
}).catch(console.error);
