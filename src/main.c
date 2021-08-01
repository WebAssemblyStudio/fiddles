#define WASM_EXPORT __attribute__((visibility("default")))

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

typedef struct {
  char *name;
  char *data;
  time_t mtime;
} file;

file *open_file(char *filename) {
  file *f = malloc(sizeof(file));
  f->name = filename;
  f->data = "agkjlajsdkfglkas";
  f->mtime = 45;
  return f;
}

void close_file(file *f) {
  free(f);
}

WASM_EXPORT
int main() {
  file *f = open_file("README.txt");
  int version = f->data[0];
  close_file(f);
  printf("Helllo!");
  return version;
}
