#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

unsigned int div_sum(unsigned int num)
{
  unsigned int sum = 0;

  for (int i = 1; i <= num / 2; i++)
  {
    if (num % i == 0)
    {
      sum += i;
    }
  }
  return sum;
}

int main()
{
  int count = 0;
  for (int i = 1; i < 10000; i++)
  {
    for (int j = i; j < 10000; j++)
    {
      if (i == div_sum(j) && div_sum(i) == j && i != j)
      {
        printf("%d  %d\n", i, j); 
        count++;     
      }
    }
    

  }
  printf("%d\n", count);
  return 0;
}