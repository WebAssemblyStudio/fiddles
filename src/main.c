
#define WASM_EXPORT __attribute__((visibility("default")))

/* External function that is implemented in JavaScript. */
extern int rt_add(int x, int y);

/* Basic implementation of the writev sys call. */
WASM_EXPORT
int add_two(int x) { return rt_add(x, 2); }