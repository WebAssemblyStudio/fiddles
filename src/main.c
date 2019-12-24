#define WASM_EXPORT __attribute__((visibility("default")))

#define ROOT "jHb9CJAWyB4jr91VRWn96DkukG4bwdtyTh"
#define TEST_0 "jpLpucnjfX7ksggzc9Qw6hMSm1ATKJe3AF"
#define TEST_1 "j9VSrHSiZPiJBPUS6iwYiT8yfy8iFbeR4E"

#define NULL 0

/* External function that is implemented in Native Lauguage. */
extern void print(char *s);

extern int jt_blockNumber();
extern int jt_getBalance(char *address, char *currency, char *issuer);

extern int jtc_getAddress(char *from);
extern int jtc_getContractAddress(char *contract);
extern int jtc_getValue();
extern int jtc_getCurrency(char *currency);
extern int jtc_getIssuer(char *issuer);
extern int jtc_move(char *from_address, char *to_address, int balance, char *currency, char *issuer);

char* itoa(int value, char* result, int base) {
  // check that the base if valid
  if (base < 2 || base > 36) { *result = '\0'; return result; }

  char* ptr = result, *ptr1 = result, tmp_char;
  int tmp_value;

  do {
    tmp_value = value;
    value /= base;
    *ptr++ = "zyxwvutsrqponmlkjihgfedcba9876543210123456789abcdefghijklmnopqrstuvwxyz" [35 + (tmp_value - value * base)];
  } while ( value );

  // Apply negative sign
  if (tmp_value < 0) *ptr++ = '-';
  *ptr-- = '\0';
  while(ptr1 < ptr) {
    tmp_char = *ptr;
    *ptr--= *ptr1;
    *ptr1++ = tmp_char;
  }
  return result;
}

void printValue(char *title, int value) {
   char *p = title;
   int len = 0;
   while(*p ++) {
     len ++;
   }
   if(len > 232){
     return;
   }
   char buf[256];
   for(int i = 0; i < len; i ++) {
     buf[i] = title[i];
   }
   buf[len] = ':';
   p = buf + len + 1;
   itoa(value, p, 10);
   print(buf);
}

WASM_EXPORT int init() {

}

WASM_EXPORT int blockNumber() {
  return jt_blockNumber();
}

WASM_EXPORT int balance(char *address, char *currency, char *issuer) {
  return jt_getBalance(address, currency, issuer);
}

WASM_EXPORT int root_balance() {
  return jt_getBalance(ROOT, NULL, NULL);
}

WASM_EXPORT int main() {
  print("Hello World.");
  int block = blockNumber();
  printValue("> block number", block);
  int rootBalance = root_balance();
  printValue("> root balance", rootBalance);
  int ret = jtc_move(ROOT, TEST_0, 100, NULL, NULL);
  printValue("> move", 100);
  return 0;
}
