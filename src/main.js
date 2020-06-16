async function run() {
  let response = await fetch('../out/main.wasm');
  let bytes = await response.arrayBuffer();
  let module = await WebAssembly.instantiate(bytes, {
    env: {
      wasm_log(start,len) {
        // Extrait le texte depuis la mémoire.
        const utf8dec = new TextDecoder("utf-8");
        let memory = new Uint8Array(module.instance.exports.memory.buffer);
        let text = utf8dec.decode(memory.subarray(start,start+len));

        // Affiche le texte à l'écran.
        document.getElementById("container").innerHTML += text+"<br>";
      }
    }
  });
  
  // Transforme "Ferris" en octets.
  const utf8enc = new TextEncoder("utf-8");
  let text = "Ferris";
  let text_bytes = utf8enc.encode(text);
  
  // Alloue de l'espace mémoire pour le texte.
  let len = text_bytes.length;
  let start = module.instance.exports.wasm_malloc(len);

  // Met le texte dans la mémoire du programme WebAssembly.
  let memory = new Uint8Array(module.instance.exports.memory.buffer);
  memory.set(text_bytes, start);

  // Exécute le programme.
  module.instance.exports.main(start,len);
}

run();