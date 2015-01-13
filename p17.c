#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

unsigned int num_letter(unsigned int num)
{
  unsigned int result = 0;

  if (num == 1000)
  {
    return 11;
  }

  int last_two = num % 100;

  switch(last_two) {
    case 1:
    case 2:
    case 6:
    case 10:
      result += 3;
      break;
    case 4:
    case 5:
    case 9:
      result += 4;
      break;
    case 3:
    case 7:
    case 8:
    case 40:
    case 50:
    case 60:
      result += 5;
      break;
    case 11:
    case 12:
    case 20:
    case 30:
    case 80:
    case 90:
      result += 6;
      break;
    case 13:
    case 14:
    case 18:
    case 19:
      result += 8;
      break;
    case 15:
    case 16:
    case 70:
      result += 7;
      break;
    case 17:
      result += 9;
      break;
    default:
      break;
  }

  if (last_two > 20 && last_two % 10 != 0)
  {
    switch(last_two % 10) {
      case 1:
      case 2:
      case 6:
        result += 3;
        break;
      case 3:
      case 7:
      case 8:
        result += 5;
        break;
      case 4:
      case 5:
      case 9:
        result += 4;
        break;
      default:
        break;
    }
    switch(last_two / 10) {
      case 2:
      case 3:
      case 8:
      case 9:
        result += 6;
        break; 
      case 4:
      case 5:
      case 6:
        result += 5;
        break;
      case 7:
        result += 7;
        break;
      default:
        break;
    }
  }

  if (num / 100 > 0)
  {
    if (num % 100 != 0)
    {
      result += 3;
    }

    switch(num / 100) {
      case 1:
      case 2:
      case 6:
        result += 10;
        break;
      case 3:
      case 7:
      case 8:
        result += 12;
        break;
      case 4:
      case 5:
      case 9:
        result += 11;
        break;
      default:
        break;
    }
  }

  return result;

}

int main()
{
  unsigned int sum = 0;
  for (int i = 1; i <= 1000; i++)
  {
    printf("%d %u\n", i, num_letter(i));
    sum += num_letter(i);
  }

  printf("%u\n", sum);
  
  return 0;
}