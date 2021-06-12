// Test passage de données depuis le DOM HTML plusieurs fois sans recharger le WASM

let instance; // l'instance du module main.wasm
let txt;      // un Uint32Array donnant accès au tableau 'txt' de main.c

/*** FONCTIONS UTILITAIRES ***/

/**
 * Fonction JS qui copie la chaîne 'str' dans le tableau 'txt'
 */
function toMemory(str) {
  for (let i=0; i<str.length; i+=1) {
    txt[i] = str.codePointAt(i);
  }
  return str.length;
}

/**
 * Fonction JS qui reconstitue une chaîne à partir du tableau 'txt' 
 */
//TODO enlever le "+ 9" à la fin, c'est juste pour montrer qu'on récupère le bon type.
function fromMemory(length) {
  console.log(length);
  document.getElementById("container").textContent = String.fromCodePoint(...txt.subarray(0, length + 9));
}

/*** APPEL DE L'API EN WASM DU REASONER ***/

/**
 * Fonction JS qui inclut l'appel à la fonction C en WASM pour faire l'ajout de faits
 */
function triggerWasmAddCall() {
  // on copie le contenu RDF dans le tableau 'txt'
  const length = toMemory(document.getElementById("addSource").value);
  // on appelle la fonction WASM du reasoner
  instance.exports.add(length, Number(document.getElementById("addType").value));
  // on affiche le tableau 'txt' dans l'interface HTML
  fromMemory(length);
}

/**
 * Fonction JS qui inclut l'appel à la fonction C en WASM pour faire la suppression de faits
 */
function triggerWasmDeleteCall() {
  // on copie le contenu RDF dans le tableau 'txt'
  const length = toMemory(document.getElementById("deleteSource").value);
  // on appelle la fonction WASM uppercase
  instance.exports.delete(length, Number(document.getElementById("deleteType").value));
  // on affiche le tableau 'txt' dans l'interface HTML
  fromMemory(length);
}

/**
 * Fonction JS qui inclut l'appel à la fonction C en WASM pour faire la comparaison de faits
 */
function triggerWasmHasCall() {
  // on copie le contenu RDF dans le tableau 'txt'
  const length = toMemory(document.getElementById("hasSource").value);
  // on appelle la fonction WASM uppercase
  instance.exports.has(length, Number(document.getElementById("hasType").value));
  // on affiche le tableau 'txt' dans l'interface HTML
  fromMemory(length);
}

/**
 * Fonction JS qui inclut l'appel à la fonction C en WASM pour faire le matching de faits
 */
function triggerWasmMatchCall() {
  // on copie le contenu RDF dans le tableau 'txt'
  const length = toMemory(document.getElementById("matchSource").value);
  // on appelle la fonction WASM uppercase
  instance.exports.match(length, Number(document.getElementById("matchType").value));
  // on affiche le tableau 'txt' dans l'interface HTML
  fromMemory(length);
}

WebAssembly.instantiateStreaming(
  fetch('../out/main.wasm'),
  // dans cet objet, on passe les fonctions importées par main.wasm
  {
    env: {
      console_log_unicode_char(code) {
        console.log(String.fromCodePoint(code));
      },
      console_log_unicode_string(codeArray) {
        //const byteArray = [65, 66, 67, 68, 69, 70];
        console.log(String.fromCharCode(...codeArray));
      }
    }
  }
).then(results => {
  // on renseigne la variable de module 'instance'
  instance = results.instance;
  // on renseigne le segment de mémoire partagée
  let memory = instance.exports.memory; 

  // on consruit le tableau dans la variable de module 'txt'
  let offset = instance.exports.txt_offset();
  let len = instance.exports.txt_len();
  txt = new Uint32Array(memory.buffer, offset, len);
  
  // on ajoute les listeners d'événements une fois que le WASM est prêt
  document.getElementById("addButton").addEventListener('click', triggerWasmAddCall);
  document.getElementById("deleteButton").addEventListener('click', triggerWasmDeleteCall);
  document.getElementById("hasButton").addEventListener('click', triggerWasmHasCall);
  document.getElementById("matchButton").addEventListener('click', triggerWasmMatchCall);
}).catch(console.error);
