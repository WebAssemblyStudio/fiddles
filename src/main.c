#define WASM_EXPORT __attribute__((visibility("default")))


#include "unicode/ucnv.h"
#include "unicode/ucsdet.h"
#include <cstdio>
#include <string>
#include <cassert>

WASM_EXPORT
int main() {
  return 42;

  using namespace std;
  assert(argc > 2);

  char const *from_code = argv[2];

  char buf[1024+1];
  FILE* fp = fopen(argv[1], "rb");

  assert(0 != fp);

  size_t read=0;
  char dest[4096]= {};
  size_t dest_cnt(0);
  size_t converted(0);

  UErrorCode uerr = U_ZERO_ERROR;
  UConverter *uconv =  ucnv_open(from_code, &uerr);

  size_t boundary = 0;
  size_t left = 0;
  while(0 < (read = fread (buf + left, 1, 1024 - left, fp))){
    buf[read] = 0;
    boundary = read;
    
    // find the last escape character to prevent boundary slicing problem
    while( buf[boundary] >= 0)
      boundary--;
    left = read - boundary;

    dest_cnt = ucnv_toAlgorithmic(
      UCNV_UTF8, uconv, dest, 4096, buf, boundary, &uerr);

    fwrite(dest, 1, dest_cnt, stdout);

    memcpy(buf, &buf[boundary], left);

    if(U_FAILURE(uerr)){
      fprintf(stderr, "error: %s\n", u_errorName(uerr));
    }
  }

  ucnv_close(uconv);
  fclose(fp);
}
