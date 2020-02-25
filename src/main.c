#define WASM_EXPORT __attribute__((visibility("default")))

#include <pthread.h>

typedef struct thread_data {
   unsigned char * arr;
   int length;
   int result;

} thread_data;

void *calculateSubset(void *vargp) 
{ 
  thread_data * data = (thread_data*)vargp;
  for (int i = 0; i < data->length; i++) {
    data->result += data->arr[i];
  }
} 

WASM_EXPORT
float avgRoot(unsigned char * arr, int length) {
  pthread_t thread;  
  thread_data data;

  data.arr = arr;
  data.length = length;
  data.result = 0;

  if (pthread_create(&thread, NULL, calculateSubset, &data)) {
        return 1;
  }

  if (pthread_join(thread, NULL)) {
        return 2;
    }

  return data.result;
}
