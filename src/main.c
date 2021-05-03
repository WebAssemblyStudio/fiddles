#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <sys/uio.h>

#define WASM_EXPORT __attribute__((visibility("default")))

typedef struct LinkedListNode
{
	void* data;
	struct LinkedListNode* next;
} LinkedListNode;
typedef struct LinkedList
{
	struct LinkedListNode* first;
	struct LinkedListNode* last;
	size_t size;
} LinkedList;

LinkedList* createLinkedList()
{
	LinkedList* l = malloc(sizeof(LinkedList));
	if (l)
	{
		l->size = 0;
		l->first = NULL;
		l->last = NULL;
	}
	
	return l;
}
WASM_EXPORT
int main() {
  char buff[255];
  LinkedList* a = createLinkedList();
  FILE *f;
  f = fopen("main.c", "r");
  fscanf(f, "%[^\n]", buff);
  if (buff[0] == NULL)
    printf("ditmemay\n");
  printf("hey %s 123\n",buff[1]);
  return a->size +1;
}

extern void putc_js(char c);
WASM_EXPORT
size_t writev_c(int fd, const struct iovec *iov, int iovcnt) {
  size_t cnt = 0;
  for (int i = 0; i < iovcnt; i++) {
    for (int j = 0; j < iov[i].iov_len; j++) {
      putc_js(((char *)iov[i].iov_base)[j]);
    }
    cnt += iov[i].iov_len;
  }
  return cnt;
}
