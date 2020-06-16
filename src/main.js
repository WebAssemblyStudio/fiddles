let instance = null;
let memoryStates = new WeakMap();

// Tu peux ignorer cette fonction, sache juste que C en a besoin.
function syscall(instance, n, args) {
  switch (n) {
    default:
      // console.log("Syscall " + n + " NYI.");
      break;
    case /* brk */ 45: return 0;
    case /* writev */ 146:
      return instance.exports.writev_c(args[0], args[1], args[2]);
    case /* mmap2 */ 192:
      debugger;
      const memory = instance.exports.memory;
      let memoryState = memoryStates.get(instance);
      const requested = args[1];
      if (!memoryState) {
        memoryState = {
          object: memory,
          currentPosition: memory.buffer.byteLength,
        };
        memoryStates.set(instance, memoryState);
      }
      let cur = memoryState.currentPosition;
      if (cur + requested > memory.buffer.byteLength) {
        const need = Math.ceil((cur + requested - memory.buffer.byteLength) / 65536);
        memory.grow(need);
      }
      memoryState.currentPosition += requested;
      return cur;
  }
}

async function run() {
  let response = await fetch('../out/main.wasm');
  let bytes = await response.arrayBuffer();
  let module = await WebAssembly.instantiate(bytes, {
    env: {
      __syscall0: function __syscall0(n) { return syscall(instance, n, []); },
      __syscall1: function __syscall1(n, a) { return syscall(instance, n, [a]); },
      __syscall2: function __syscall2(n, a, b) { return syscall(instance, n, [a, b]); },
      __syscall3: function __syscall3(n, a, b, c) { return syscall(instance, n, [a, b, c]); },
      __syscall4: function __syscall4(n, a, b, c, d) { return syscall(instance, n, [a, b, c, d]); },
      __syscall5: function __syscall5(n, a, b, c, d, e) { return syscall(instance, n, [a, b, c, d, e]); },
      __syscall6: function __syscall6(n, a, b, c, d, e, f) { return syscall(instance, n, [a, b, c, d, e, f]); },
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
  
  instance = module.instance;

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
  module.instance.exports.run(start,len);
}

run();