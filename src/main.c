#define WASM_EXPORT __attribute__((visibility("default")))
#include <stdio.h>
WASM_EXPORT
int main() {
  return 420.69;
}

void swap(int *xp, int *yp)  
{  
    int temp = *xp;  
    *xp = *yp;  
    *yp = temp;  
}  

WASM_EXPORT
char* hi(){
   int arr[] = { 1, 2, 5, 6, 8, 9 };
   int n = 6;
   int i, j; 
   for (i = 0; i < n-1; i++)       
  
       // Last i elements are already in place    
       for (j = 0; j < n-i-1; j++)  
           if (arr[j] > arr[j+1]) 
              swap(&arr[j], &arr[j+1]); 

    char str[100];
    sprintf(str,"%d%d%d%d%d",arr[0],arr[1],arr[2],arr[3], arr[4], arr[5]);
    return *str;
}