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
int main(int argc, char const *argv[])
{
  unsigned long max = 3;
  unsigned long count = 3;

  while(count < sqrt(600851475143))
  {
    if ((600851475143 % (count) == 0)&& is_prime(count))
    {
      max = count;
    }

    count += 2;
  }

  printf("%lu\n", max);
  return 0;
}