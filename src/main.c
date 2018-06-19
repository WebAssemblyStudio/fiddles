#define WASM_EXPORT __attribute__((visibility("default")))

int load(void* key, int keyLength, void* value, int valueLength);
int loadData(void* key, void* value);

struct address {
  double a;
  double b;
  double c;
};
struct address addr0 = {1,1,1};
struct address addr1 = {2,2,2};
struct address addr2 = {3,3,3};

struct addrMap {
  struct address a;
  struct address b;
};

struct addrMap mapping = {{4,4,4},{5,5,5}};

WASM_EXPORT
int start(int i){
  if(i == 0) return load(&mapping, sizeof(mapping), &addr0, sizeof(addr0));
  if(i == 1) return load(&mapping, sizeof(mapping), &addr1, sizeof(addr1));
  return load(&mapping, sizeof(mapping), &addr1, sizeof(addr1));
}