#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

struct date_header{
  int day;
  int month;
  int year;
  int week_day;
};

typedef struct date_header * date;
bool is_leap(date D)
{
  if (D->year % 4 != 0)
  {
    return false;
  }
  else
  {
    if (D->year % 100 == 0)
    {
      if (D->year % 400 == 0)
      {
        return true;
      }
      else
      {
        return false;
      }
    }
    else
    {
      return true;
    }
  }

}

void iterate_date(date D)
{
  D->week_day = (D->week_day + 1) % 7;

  switch(D->month){
    case 0:
    case 2:
    case 4:
    case 6:
    case 7:
    case 9:
    case 11:
      D->day = (D->day + 1) % 31;
      break;
    case 3:
    case 5:
    case 8:
    case 10:
      D->day = (D->day + 1) % 30;
      break;
    case 1:
      if (is_leap(D))
        D->day = (D->day + 1) % 29;
      else
        D->day = (D->day + 1) % 28;
      break;
  }

  if (D->day == 0)
  {
    D->month = (D->month + 1) % 12;
  }

  if (D->month == 0 && D->day == 0)
  {
    D->year++;
  }


}

void print_date(date D)
{
  printf("%d-%d-%d, %d\n", D->month + 1, D->day + 1, D->year, D->week_day + 1);
}

int main()
{
  date D = malloc(sizeof(struct date_header));
  
  D->day = 0;
  D->month = 0;
  D->year = 1901;
  D->week_day = 2;

  int num = 0;

  while(!(D->day == 0 && D->month == 0 && D->year == 2001))
  {
    if (D->day == 0 && D->week_day == 6)
    {
      num++;
    }
    print_date(D);
    iterate_date(D);
  }
  
  printf("%d\n", num);

  return 0;
}