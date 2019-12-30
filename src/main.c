#define WASM_EXPORT __attribute__((visibility("default")))
#include <math.h>

WASM_EXPORT
double main() {
  return sin(21);
}

int *dataArray= {0};//, 0, 0, 0, 0};
WASM_EXPORT
int init(int inArray[], int len) {
	//*dataArray = *inArray;
	int sum = 0;
	for(int i = 0; i < len; i++) {
		dataArray[i] = inArray[i];
		sum  += inArray[i];//dataArray[i];
	}
	return sum;
}
WASM_EXPORT
int processData(int len) {
	//printf("DD");
	int sum = 0;
	for(int i = 0; i < len; i++) {
		dataArray[i]++;
		sum  += dataArray[i];
	}
	return sum;
}
