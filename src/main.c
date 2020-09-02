#include <stdio.h>
#include <sys/uio.h>

#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int sumar(int numero1, int numero2)
{
	return numero1 + numero2;
}

WASM_EXPORT
int main(void) {
  printf("Hello World\n");
  int suma = sumar(5, 3); /* Se ejecuta correctamente*/
	printf("La suma es: %d ", suma);
	return 0;
}

/* External function that is implemented in JavaScript. */
extern void putc_js(char c);

/* Basic implementation of the writev sys call. */ 



