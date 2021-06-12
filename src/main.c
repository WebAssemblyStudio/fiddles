#define WASM_EXPORT __attribute__((visibility("default")))

// par défaut, le module WASM exporte un segment de mémoire partagé, sous le nom 'memory'

// un tableau de codes Unicode, qui sera accessible dans le segment 'memory' -> utilisé pour passer des faits
#define TXT_LEN 4096
unsigned int txt[TXT_LEN];

// une fonction importée depuis le code JS (dans le namespace 'env')
extern void console_log_unicode_char(int code);
// extern void console_log_unicode_string(char* code);

// la variable qui stockera un format de sérialisation RDF
char type[8];
/*
void set_type(unsigned short code) {
  switch (code) {
      case 0: strcpy(type,"TURTLE"); console_log_unicode_string(type); break;
      case 1: strcpy(type,"NTRIPLES"); console_log_unicode_string(type); break;
      case 2: strcpy(type,"NQUADS"); console_log_unicode_string(type); break;
      case 3: strcpy(type,"TRIG"); console_log_unicode_string(type); break;
      default : strcpy(type,"ERROR"); console_log_unicode_string("Invalid type code.");
   }  
}
*/

// une fonction qui fait juste du décalage dans une chaîne pour tester
int transform(unsigned int txt_len, int shift) {
  for (unsigned int i=0; i<txt_len; i+=1) {
    console_log_unicode_char(txt[i]);
    if ('a' <= txt[i] && txt[i] <= 'z') {
      txt[i] += shift;
    }
  }
  return 0;
}

/*** FONCTIONS "TECNIQUES" WASM ***/

// une fonction exportée sous le nom 'txt_offset' qui retourne l'adresse de 'txt'
// NB: le pointeur C sera converti en entier dans le code WASM représentant un offset dans le segment 'memory'
WASM_EXPORT
void* txt_offset() {
  return txt;
}

// une fonction exportée sous le nom 'txt_len' qui retourne la taille (en octets) de 'txt'
WASM_EXPORT
unsigned int txt_len() {
  return TXT_LEN * sizeof(unsigned int);
}

/*** API DU REASONER ***/

WASM_EXPORT
int add(unsigned int txt_len, unsigned short type_code) {
//  set_type(type_code);
  return transform(txt_len, 1);
}
WASM_EXPORT
int add_basic(unsigned int txt_len) {
  console_log_unicode_char(150);
//  set_type(type_code);
  return transform(txt_len, 1);
}

WASM_EXPORT
int delet(unsigned int txt_len, unsigned short type_code) {
//  set_type(type_code);
  return transform(txt_len, -1);
}

WASM_EXPORT
int has(unsigned int txt_len, unsigned short type_code) {
//  set_type(type_code);
  return transform(txt_len, -32);
}

WASM_EXPORT
int match(unsigned int txt_len, unsigned short type_code) {
//  set_type(type_code);
  return transform(txt_len, 32);
}
