#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <gmp.h>

mpz_t factorial(mpz_t num)
{
  
  while(count <= num)
  {
    prod = prod * count;
    count++;
  }

  return prod;
}

unsigned int sum(unsigned long long num)
{
  unsigned int sum = 0;
  while(num > 0)
  {
    sum += num % 10;
    num = num / 10;
  }

  return sum;
}
int main()
{
  for (int i = 0; i < 20; ++i)
  {
    printf("%d %llu %u\n", i, factorial(i), sum(factorial(i)));
  }
  
  return 0;
}