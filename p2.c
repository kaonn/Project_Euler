#include <stdlib.h>
#include <stdio.h>
int main(int argc, char const *argv[])
{
  unsigned int sum = 0;
  unsigned int a = 1;
  unsigned int b = 2;
  while(a < 4000000)
  {
    if (a % 2 == 0)
    {
      sum += a;
    }
    if (b % 2 == 0)
    {
      sum += b;
    }
    a = a + b;
    b = a + b;
  }
  printf("%d\n", sum);
  return 0;
}