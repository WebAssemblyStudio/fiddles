#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int main() {
  int i,j,k,l,m,n;
  int result = 0;
  int max = 2147483647;
  for(i=0; i<max; i++){
    for(j=0; j<max; j++){
      for(k=0; k<max; k++){
        for(l=0; l<max; l++){
          for(m=0; m<max; m++){
            for(n=0; n<max; n++){
              if(i==j && j==k && k==l && l==m && m==n){
                result = i;
              }else{
                result = n;
              }
            }
          }
        }
      }
    }
  }
  return 0;
}
