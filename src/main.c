#include <stdio.h>

void main(){
  long sum = 0;
  for (int i = 1; i <= 30; i++){
    int a, b;
    if (i % 2 == 1){
      a = i;
      b = i * i;
    } else {
      a = i / 2;
      b = i * i * i;
    }
    sum += (a - b) * (a - b);
  }
  printf("%d", sum);
}