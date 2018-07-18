#define WASM_EXPORT __attribute__((visibility("default")))

unsigned char *data = 0;

WASM_EXPORT
unsigned char *allocMemory(int size)
{
  data = 0;//(unsigned char*)malloc(size);
  return data;
}

int main()
{
  return 0;
}
