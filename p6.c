#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int main()
{
  unsigned int sum = 0;

  for (int i = 1; i <= 100; i++)
  {
    for (int j = 1; j <= 100; j++)
    {
      if (i != j)
      {
        sum += i * j;
      }
    }
  }

  printf("%d\n", sum);
  return 0;
}