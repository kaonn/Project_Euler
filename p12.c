#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

unsigned long triangle(unsigned long num)
{
  return num*(num + 1)/2;
}
unsigned int num_divisor(unsigned long num)
{
  unsigned int count = 2;

  for (unsigned long i = 2; i <= num/2; i++)
  {
    if (num % i == 0)
    {
      count++;
    }
  }

  return count;
}
int main()
{
  unsigned int count = 1;
  unsigned int i = 11168;
  
  printf("%lu\n", triangle(12375));
  return 0;
}
