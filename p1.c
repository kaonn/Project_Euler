#include <stdlib.h>
#include <stdio.h>

int main()
{
  unsigned int count = 0;
  for (size_t i = 1; i < 1000; i++)
  {
    if (i % 5 == 0 || i % 3 == 0)
    {
      count += i;
    }
  }
  printf("%d\n", count);
  return 0;
}