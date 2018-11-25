#include <stdio.h>
#include <sys/uio.h>
#include <stdbool.h>
#include <stdlib.h>


#define MAX 100

//int list[MAX] = {1,8,4,6,0,3,5,2,7,9};
int list[MAX];


void display() {
   int i;
   printf("[");
	
   // navigate through all items 
   for(i = 0; i < MAX; i++) {
      printf("%d ",list[i]);
   }
	
   printf("]\n");
}

void bubbleSort() {
   int temp;
   int i,j;
	
   bool swapped = false;
   
   // loop through all numbers 
   for(i = 0; i < MAX-1; i++) { 
      swapped = false;
		
      // loop through numbers falling ahead 
      for(j = 0; j < MAX-1-i; j++) {

         // check if next number is lesser than current no
         //   swap the numbers. 
         //  (Bubble up the highest number)
			
         if(list[j] > list[j+1]) {
            temp = list[j];
            list[j] = list[j+1];
            list[j+1] = temp;

            swapped = true;
         }			
      }

      // if no number was swapped that means 
      //   array is sorted now, break the loop. 
      if(!swapped) {
         break;
      }
      
      //display();
   }
	
}

#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
int main(void) {
  for(int i = 0; i < 100; ++i)
{
  list[i] = rand() % MAX + 1;
}
  printf("Hello World\n");
  printf("Input Array: ");
  display();
  printf("\n");

  bubbleSort();
  printf("\nOutput Array: ");
  display();
}

/* External function that is implemented in JavaScript. */
extern void putc_js(char c);

/* Basic implementation of the writev sys call. */ 
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
