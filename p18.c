#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

const int HEIGHT = 15;
int pyramid[][HEIGHT] = {
{75},
{95, 64},
{17, 47, 82},
{18, 35, 87, 10},
{20, 04, 82, 47, 65},
{19, 01, 23, 75, 03, 34},
{88, 02, 77, 73, 07, 63, 67},
{99, 65, 04, 28, 06, 16, 70, 92},
{41, 41, 26, 56, 83, 40, 80, 70, 33},
{41, 48, 72, 33, 47, 32, 37, 16, 94, 29},
{53, 71, 44, 65, 25, 43, 91, 52, 97, 51, 14},
{70, 11, 33, 28, 77, 73, 17, 78, 39, 68, 17, 57},
{91, 71, 52, 38, 17, 14, 91, 43, 58, 50, 27, 29, 48},
{63, 66, 04, 68, 89, 53, 67, 30, 73, 16, 69, 87, 40, 31},
{04, 62, 98, 27, 23,  9, 70, 98, 73, 93, 38, 53, 60, 04, 23},
};

struct node_header
{
  struct node_header *left;
  struct node_header *right;
  int data;
};

typedef struct node_header *node;

unsigned long triangle(unsigned long num)
{
  return num*(num + 1)/2;
}

void init(int pyramid[][HEIGHT], node N[])
{
  for (int i = 0; i < HEIGHT - 1; i++)
  {
    for (int j = 0; j < i + 1; j++)
    {
      int index = triangle(i) + j;
      N[index] = malloc(sizeof(struct node_header));
    }
  }

  for (int i = 0; i < HEIGHT - 1; i++)
  {
    int index = triangle(HEIGHT - 1) + i;
    N[index] = malloc(sizeof(struct node_header));
    N[index]->data = pyramid[HEIGHT - 1][i];
  }

  for (int i = 0; i < 14; i++)
  {
    for (int j = 0; j < i + 1; j++)
    {
      int index = triangle(i) + j;
      int index_next = triangle(i + 1) + j;
      N[index]->left = N[index_next];
      N[index]->right = N[index_next + 1];
      N[index]->data = pyramid[i][j];
    }
  }

}

unsigned long max_path(node N)
{
  if(N == NULL)
  {
    return 0;
  }
  if (N->left == NULL)
  {
    return N->data;
  }

  return N->data + fmax(max_path(N->left), max_path(N->right));
}

int main()
{
  
  node N[120];
  init(pyramid, N);

  printf("%lu\n", max_path(N[0]));
  return 0;
}