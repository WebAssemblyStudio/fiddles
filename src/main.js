var i = document.querySelector("input");
var c = document.getElementById("container");

// chargement du module...
WebAssembly.instantiateStreaming(
  fetch('../out/main.wasm'),
  {},
)
.then((result) => {
  let instance = result.instance;
  let array = new Uint8Array(
    instance.exports.memory.buffer,
    instance.exports.get_offset(),
    instance.exports.get_size(),
  );
  i.addEventListener('input', () => {
    // transfère i.value dans le buffer, caractère par caractère
    for (let j=0; j<i.value.length; j++) {
      array[j] = i.value.charCodeAt(j);
    }
    // appelle la fonction WebAssembly pour passer buffer en majuscules
    instance.exports.upper();
    // extrait et affiche les caractères du buffer
    c.innerText = "";
    for (let j=0; j<i.value.length; j++) {
      c.innerText += String.fromCharCode(array[j]);
    }
  });
})
.catch((err) => {
  console.log("Error" + err);
});

function stringToBuffer(s) {
  
}
  
