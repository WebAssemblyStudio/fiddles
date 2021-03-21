#define WASM_EXPORT __attribute__((visibility("default")))
//permite que o web assembly "veja" as funções


int main() {
  return 42;
}

WASM_EXPORT
char* fatorial5(){
  return "Fatorial(5)=";
}

WASM_EXPORT
char* fibonacci5(){
  return "Fibonacci(5)=";
}

WASM_EXPORT
int fatorial(int n){
  if(n>1){
    return fatorial((n-1))*n;
  }
  else{
    return 1;
  }
}

WASM_EXPORT
int fibonacci(int n){
  if(n>1){
    return fibonacci(n-1)+fibonacci(n-2);
  }
  else{
    return 1;
  }
}