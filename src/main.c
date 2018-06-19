#define WASM_EXPORT __attribute__((visibility("default")))
#define WASM_IMPORT __attribute__((visibility("default")))

struct address {
  unsigned int prefix;
  unsigned long long body;
  unsigned long long suffix;
};
struct address addr;

WASM_EXPORT
int initialize(unsigned int prefix,unsigned long long body,unsigned long long suffix){
  addr.prefix = prefix;
  addr.body=body;
  addr.suffix=suffix;
  return 0;
}