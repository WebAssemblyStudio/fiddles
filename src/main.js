let instance; // l'instance du module main.wasm
let txt;      // un Uint32Array donnant accès au tableau 'txt' de main.c

// wrapper pour la fonction WASM uppercase
function uppercase(str) {
  // on copie la chaîne 'str' dans le tableau 'txt'
  for (let i=0; i<str.length; i+=1) {
    txt[i] = str.codePointAt(i);
  }
  // on appelle la fonction WASM uppercase
  instance.exports.uppercase(str.length);
  // on reconstitue une chaîne à partir du tableau 'txt'
  return String.fromCodePoint(...txt.subarray(0, str.length));
}

function add(str,index){
  
}



WebAssembly.instantiateStreaming(
  fetch('../out/main.wasm'),
  // dans cet objet, on passe les fonctions importées par main.wasm
  {
    env: {
      console_log_unicode_char(code) {
        console.log(String.fromCodePoint(code));
      }
    }
  }
).then(results => {
  // on renseigne la variable de module 'instance'
  instance = results.instance;

  // on consruit le tableau dans la variable de module 'txt'
  let memory = instance.exports.memory; // le segment de mémoire partagée
  let offset = instance.exports.txt_offset();
  let len = instance.exports.txt_len();
  txt = new Uint32Array(memory.buffer, offset, len);

  // exemple d'utilisation des fonctions WASM
  // NB: la fonction JS uppercase utilise, en interne,
  //     la fonction uppercase(int) définie dans main.c
  //document.getElementById("container").textContent = uppercase("hello world!");
  //document.getElementById("container").textContent = add("1",0);
  //document.getElementById("container").textContent = add("2",1);
  
}).catch(console.error);
