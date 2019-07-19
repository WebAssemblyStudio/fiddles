#define WASM_EXPORT __attribute__((visibility("default")))

#define GET_USERAGENT_ID 10
#define CALL_ALERT_ID 20

/* External function that is implemented in JavaScript. */
extern void entry(int id, void* ptr);

WASM_EXPORT
int main(void) {
  char userAgent[256];
  entry(GET_USERAGENT_ID, (void*)userAgent);
  entry(CALL_ALERT_ID, (void*)userAgent);
}

