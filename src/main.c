#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

int sum(int a, int b);
int main()
{
   int x = 0;
   int y = 0;
   int z = 0;
   int result = 0;
   int score = 0;
   printf("500점을 달성하세요!!\n");
   while (1)
   {
      if (score >= 500 || score < 0) {
         break;
      }
      else {
         printf("정수 두개 입력\n");
         scanf("%d %d", &x, &y);
         result = sum(x, y);

         printf("두 수의 합은 무엇일까요?\n");
         scanf("%d", &z);

         if (result == z)
         {
            score += 100;
            printf("Good!!, score = %d\n", score);
         }
         else
         {
            score -= 50;
            printf("Bad.. The sum is %d, score=%d\n", result, score);
         }
      }
   }
   if (score >= 500) {
      printf("You Win!!!\n");
   }
   else printf("You failed..\n");
   system("pause");
}
int sum(int a, int b)
{
   int result = 0;
   result = a + b;
   return result;
}

