var importObject = {
  imports: {
    say_hello: function () {
      alert("I hope you're enjoying this lunch and learn!");
    }
  }
};

WebAssembly.instantiateStreaming(fetch('../out/main.wasm'), importObject)
  .then(results => {
    instance = results.instance;
    document.getElementById("container").textContent = instance.exports.getAnswerPlus1();
  }).catch(console.error);
