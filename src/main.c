#define WASM_EXPORT __attribute__((visibility("default")))
#include<string.h>

// par défaut, le module WASM exporte un segment de mémoire partagé, sous le nom 'memory'

// un tableau de codes Unicode, qui sera accessible dans le segment 'memory' -> utilisé pour passer des faits
#define TXT_LEN 4096
unsigned int txt_in[TXT_LEN];
unsigned int txt_out[TXT_LEN];

// une fonction importée depuis le code JS (dans le namespace 'env')
extern void console_log_unicode_char(int code);
extern void console_log_unicode_string(char code[]);

// la variable qui stockera un format de sérialisation RDF
char type[9];

void set_type(unsigned short code) {
  switch (code) {
      case 0: strcpy(type,"TURTLE"); break;
      case 1: strcpy(type,"NTRIPLES"); break;
      case 2: strcpy(type,"NQUADS"); break;
      case 3: strcpy(type,"TRIG"); break;
      default : strcpy(type,"ERROR");
   }
}

// une fonction qui fait juste du décalage dans une chaîne pour tester
// ...plus qui rajoute un tiret et le type.
int transform(unsigned int txt, unsigned int txt_len, int shift) {
  int i;
  for (i=0; i<txt_len; i+=1) {
    console_log_unicode_char(txt[i]);
    if ('a' <= txt[i] && txt[i] <= 'z') {
      txt[i] += shift;
    }
  }
  txt[txt_len] = '-';
  for (i=0; i<9 && type[i]!=0; i+=1) {
    console_log_unicode_char(type[i]);
    txt[txt_len + i + 1] = type[i];
  }
  txt[txt_len + i + 1] = 0;

  return i;
}

/*** FONCTIONS "TECNIQUES" WASM ***/

// une fonction exportée sous le nom 'txt_in_offset' qui retourne l'adresse de 'txt_in'
// NB: le pointeur C sera converti en entier dans le code WASM représentant un offset dans le segment 'memory'
WASM_EXPORT
void* txt_in_offset() {
  return txt_in;
}

// une fonction exportée sous le nom 'txt_in_len' qui retourne la taille (en octets) de 'txt_in'
WASM_EXPORT
unsigned int txt_in_len() {
  return TXT_LEN * sizeof(unsigned int);
}

// une fonction exportée sous le nom 'txt_out_offset' qui retourne l'adresse de 'txt_out'
// NB: le pointeur C sera converti en entier dans le code WASM représentant un offset dans le segment 'memory'
WASM_EXPORT
void* txt_out_offset() {
  return txt;
}

// une fonction exportée sous le nom 'txt_out_len' qui retourne la taille (en octets) de 'txt_out'
WASM_EXPORT
unsigned int txt_out_len() {
  return TXT_LEN * sizeof(unsigned int);
}

/*** API DU REASONER ***/
WASM_EXPORT
int test(unsigned int txt_len) {
  return 0;
}

WASM_EXPORT
int add(unsigned int txt_in_len, unsigned short type_code) {
  set_type(type_code);
  return transform(txt_in, txt_in_len, 1);
}

WASM_EXPORT
int delete(unsigned int txt_in_len, unsigned short type_code) {
  set_type(type_code);
  return transform(txt_in, txt_in_len, -1);
}

WASM_EXPORT
int has(unsigned int txt_in_len, unsigned short type_code) {
  set_type(type_code);
  return transform(txt_in, txt_in_len, -32);
}

WASM_EXPORT
int match(unsigned int txt_in_len, unsigned short type_code) {
  set_type(type_code);
  return transform(txt_in, txt_in_len, 32);
}
