#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int main() {
  return 42;
}

WASM_EXPORT
char * test() {
  return "Türkçe Fıstıkçı Şahap";
}

WASM_EXPORT
int fileLoad(char *buffer, int size)
{
  for(int i = 0; i < size ; i++)
  {
    if(buffer[i] > 0) return buffer[i];
  }

  return size;
}
