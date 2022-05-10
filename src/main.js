var c = document.getElementById("container");

// chargement du module...
WebAssembly.instantiateStreaming(
  fetch('../out/main.wasm'),
  {
    // ... en lui passant l'implémentations des fonctions 'extern'
    env: {
      print_int: (i) => { c.innerText += "" + i + "\n"; },
    }
  },
)
.then((result) => {
  let instance = result.instance;
  instance.exports.count(5);
})
.catch((err) => {
  console.log("Error" + err);
});
  
