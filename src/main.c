#define WASM_EXPORT __attribute__((visibility("default")))

// par défaut, le module WASM exprte un segment de mémoire partagé,
// sous le nom 'memory'

// un tableu de codes Unicode,
// qui sera accessible dans le segment 'memory'
#define TXT_LEN 4096
unsigned int txt[TXT_LEN];

// une fonction exportée sous le nom 'txt_offset'
// retourne l'adresse de 'txt'
// NB: le pointeur C sera converti en entier das le code WASM,
//     représentant un offset dans le segment 'memory'
WASM_EXPORT
void* txt_offset() {
  return txt;
}

// une fonction exportée sous le nom 'txt_len'
// retourne la taille (en octets) de 'txt'
WASM_EXPORT
unsigned int txt_len() {
  return TXT_LEN * sizeof(unsigned int);
}

// une fonction importée depuis le code JS (dans le namespace 'env')
// (cf. dans main.js, lignes 19-26)
extern void console_log_unicode_char(int code);

// une fonction exportée sous le nom 'uppercase'
// qui passe en majuscule les 'txt_len' premiers caractères de 'txt'
WASM_EXPORT
void uppercase(unsigned int txt_len) {
  for (unsigned int i=0; i<txt_len; i+=1) {
    console_log_unicode_char(txt[i]);
    if ('a' <= txt[i] && txt[i] <= 'z') {
      txt[i] -= 32;
    }
  }
}



