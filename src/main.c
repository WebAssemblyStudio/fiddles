#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define WASM_EXPORT __attribute__((visibility("default")))

struct Books
{
  char title[50];
  char author[50];
  char subject[100];
  int book_id;
};

struct Books Book1; /* Declare Book1 of type Book */
struct Books *Book2; /* Declare Book2 of type Book */

WASM_EXPORT
int main()
{
 Book2 = (struct Books *) malloc(sizeof(struct Books));
  strcpy( Book2->title, "C Programming");
   strcpy( Book1.author, "Nuha Ali");
   strcpy( Book1.subject, "C Programming Tutorial");
   Book1.book_id = 6495407;
  return Book1;
}
