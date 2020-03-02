#define WASM_EXPORT __attribute__((visibility("default")))

int main(void)) {
  char *cp[3] = {"abc","cd","e"};
    printf("ポインタのアドレスは%p番地\n",&cp);
    printf("%sのアドレスは",*cp);
    printf("0x%x番地\n",cp);
    printf("0x%x番地\n",cp[1]);
  return 0;
}
