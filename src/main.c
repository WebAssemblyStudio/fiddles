#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int answer() {
  return 42;
}

/*
NB: WebAssembly et Javascripts ne peuvent se communiquer que des nombres
(entiers ou flottant). Pas de chaînes de caractères, d'objets...
*/
