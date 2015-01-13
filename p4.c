#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool is_palindrome(unsigned int n)
{
  size_t num_digits = log10(n) + 1;
  char str[num_digits];
  sprintf(str, "%u", n);

  for (size_t i = 0; i <= (num_digits - 2)/2; i++)
  {
    if (str[i] != str[num_digits - 1 - i])
    {
      return false;
    }
  }

  return true;
}

int main()
{
  unsigned int max = 0;

  for (int i = 100; i <= 999; i++)
  {
    for (int j = i; j <= 999; j++)
    {
      if (is_palindrome(i * j) && i * j > max)
      {
        max = i * j;
      }
    }
  }
  printf("%u\n", max);
  return 0;
}
