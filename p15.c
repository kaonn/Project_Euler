#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

unsigned long grid[21][21] = {0};

int main()
{
  for (int i = 0; i < 21; i++)
  {
    grid[0][i] = 1;
    grid[i][0] = 1;
  }

  for (int i = 1; i < 21; i++)
  {
    for (int j = 1; j < 21; j++)
    {
      grid[i][j] = grid[i][j - 1] + grid[i - 1][j];
    }
  }

  printf("%lu\n", grid[20][20]);
  return 0;
}