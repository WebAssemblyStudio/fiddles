#define WASM_EXPORT __attribute__((visibility("default")))
/*
WASM_EXPORT
int main() {
  return 42;
}*/

WASM_EXPORT
char *  helloWorld(){
  return "Helo World";
}
WASM_EXPORT
int checkUserName(const char*name){
  if(name=="a")
    return 1;
  else
  return 0;
}
WASM_EXPORT
int checkPassword(const char*pass){
  if(pass=="a")
    return 1;
  else
  return 0;
}

