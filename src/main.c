#define WASM_EXPORT __attribute__((visibility("default")))

// par défaut, le module WASM exprte un segment de mémoire partagé,
// sous le nom 'memory'

// un tableu de codepoints Unicode,
// qui sera accessible dans le segment 'memory'
#define TXT_LEN 4096;
unsigned int* txt[TXT_LEN];

// une fonction exportée sous le nom 'txt_offset'
// NB: le pointeur C sera converti en WASM en entier,
//     représentant un offset dans le segment 'memory'
WASM_EXPORT
int* txt_offset() {
  return txt;
}

// une fonction exportée sous le nom 'txt_len'
WASM_EXPORT
unsigned int txt_len() {
  return TXT_LEN;
}

// une fonction importée depuis le code JS (dans le namespace 'env')
// (cf. dans main.js, l'appel à WebAssembly.instantiateStreaming)
extern void console_log_int();

// une fonction exportée sous le nom 'uppercase'
// qui utilise implicitement txt en entrée/sortie
WASM_EXPORT
void uppercase(unsigned int txt_len) {
  for (unsigned int i=0; i<txt_len; i+=1) {
    console_log_int(txt[i]);
    if ('a' <= txt[i] && txt[i] <= 'z') {
      txt[i] -= 32;
    }
  }
}



