#define WASM_EXPORT __attribute__((visibility("default")))

extern void setText();

WASM_EXPORT
void onClick(int i) {
 setText(i + rand());
}

