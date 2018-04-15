#include <stdio.h>
#include <sys/uio.h>
#include <string.h>

#define WASM_EXPORT __attribute__((visibility("default")))



WASM_EXPORT
int main() {

  return 321;
}
char * mainStr() {
  printf("Hello World to console \n");
  return  "HelloWorld to browser";

}