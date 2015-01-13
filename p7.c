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
  unsigned int count = 1;
  unsigned long prime = 3;
  while(count < 10001)
  {
    if (is_prime(prime))
    {
      count++;
    }
    prime += 2; 
  }

  printf("%lu\n", prime - 2);
  return 0;
}