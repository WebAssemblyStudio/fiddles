#define WASM_EXPORT __attribute__((visibility("default")))

extern void console_log_char_int(int c, int i);
extern void core_store(int i);
extern int core_get();
extern void core_inc();


WASM_EXPORT
void store(int v) {
  core_store(v);
  console_log_char_int('s', v);
}

WASM_EXPORT
int get() {
  int v = core_get();
  console_log_char_int('g', v);
  return v;
}

WASM_EXPORT
void inc() {
  core_inc();
  console_log_char_int('i', core_get());
}
