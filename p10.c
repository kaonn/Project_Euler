#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool is_prime(unsigned long n)
{
  for (unsigned long i = 2; i <= sqrt(n); i++)
  {
    if (n % i == 0)
    {
      return false;
    }
  }

  return true;
}

int main()
{
  unsigned long sum = 0;

  for (unsigned long i = 2; i < 2000000; i++)
  {
    if (is_prime(i))
    {
      sum += i;
    }
  }

  printf("%lu\n", sum);
  return 0;
}