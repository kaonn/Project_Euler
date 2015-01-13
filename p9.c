#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int main()
{
  for (int i = 1; i < 1000; i++)
  {
    for (int j = i; j < 1000; j++)
    {
      if (i * i + j * j == pow(1000 - (i + j), 2))
      {
        printf("%d\n", i * j * (1000 - i - j));
      }
    }
  }
  return 0;
}