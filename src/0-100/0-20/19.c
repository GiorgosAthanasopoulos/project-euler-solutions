#include <stdio.h>

typedef enum Month {
  JAN = 0,
  FEB,
  MAR,
  APR,
  MAY,
  JUN,
  JUL,
  AUG,
  SEP,
  OCT,
  NOV,
  DEC
} Month;

typedef enum Day { MON = 0, TUE, WED, THU, FRI, SAT, SUN } Day;

int isLeapYear(int year) {
  if (year == 2000)
    return 1;
  return year % 4 == 0;
}

int getDaysInMonth(Month month, int year) {
  switch (month) {
  case SEP:
  case APR:
  case JUN:
  case NOV:
    return 30;
  case JAN:
  case MAR:
  case MAY:
  case JUL:
  case AUG:
  case OCT:
  case DEC:
    return 31;
  case FEB:
    return isLeapYear(year) ? 29 : 28;
  }
  return -1;
}

int main(void) {
  printf("[INFO]: Problem: https://projecteuler.net/problem=19\n");
  printf("[INFO]: Description: How many Sundays fell on the first of the month "
         "during the twentieth century(1-1-1901->31-12-2000)?\n");

  int currDate = 1;
  Month currMonth = JAN;
  int currYear = 1900;
  int firstDayOfMonthSundayCounter = 0;

  while (currYear <= 2000) {
    if (currYear >= 1901 && currDate == 1)
      firstDayOfMonthSundayCounter++;

    currDate += 7;
    int maxMonthDate = getDaysInMonth(currMonth, currYear);
    if (currDate > maxMonthDate) {
      currDate -= maxMonthDate;
      currMonth++;

      if (currMonth > DEC) {
        currMonth = JAN;
        currYear++;
      }
    }
  }

  printf("[INFO]: Solution: %d\n", firstDayOfMonthSundayCounter);
  return 0;
}
