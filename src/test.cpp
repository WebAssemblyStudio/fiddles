#include <stdio.h>

class TT
{
public:
  TT(int value)
  : a(value), b(value * value)
  {
  }

  int dump(void)
  {
    printf("a => %d, b => %d\n", a, b);
    return 10;
  }

private:
  int a;
  int b;
};

extern "C"
int TT_test(void)
{
  TT a(10);

  a.dump();
}
