#define WASM_EXPORT __attribute__((visibility("default")))
#include <emscripten.h>
WASM_EXPORT

int main(int argc, char ** argv) {
    printf("WebAssembly module loaded\n");
}
// 返回1-6之间的一随机数
int EMSCRIPTEN_KEEPALIVE roll_dice() {
    srand ( time(NULL) );
    return rand() % 6 + 1;
}