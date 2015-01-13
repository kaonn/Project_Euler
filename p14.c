#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

unsigned long collatz_next(unsigned long curr)
{
  return curr % 2 ? (3 * curr + 1) : curr / 2;
}

int main()
{
  unsigned int max = 0;
  unsigned int pos = 0;
  unsigned int length = 1;

  for (unsigned long i = 837799; i <  837799 + 1; i++)
  {
    unsigned long temp = i;

    while(i > 1)
    {
      printf("%lu\n ",i);
      i = collatz_next(i);
      
      length++;
    }

    
    if (length > max)
    {
      max = length;
      pos = temp;
    }

    length = 1;

    i = temp;
    printf("\n");

  }

  printf("%u\n", pos);
  return 0;
}