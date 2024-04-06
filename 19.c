#include <stdio.h>
int leap_year(int year) {
  if (year == 1900) {
    return 0;
  } else if (year == 2000) {
    return 1;
  }
  return year % 4 == 0;
}
int main() {
  int date = 1;    // mon
  int day = 1;     // 1st
  int month = 1;   // jan
  int year = 1900; // 1900
  int res = 0;
  while (day + month + year < 2043) {
    date++;
    if (date == 8) {
      date = 1;
    }
    day++;
    if (day == 31 && (month == 9 || month == 4 || month == 6 || month == 11)) {
      day = 1;
      month++;
    } else if (day == 32 &&
               (month == 1 || month == 3 || month == 5 || month == 7 ||
                month == 8 || month == 10 || month == 12)) {
      day = 1;
      month++;
      if (month == 13) {
        month = 1;
        year++;
      }
    } else if (day == 29 && !leap_year(year) && month == 2) {
      day = 1;
      month++;
    } else if (day == 30 && leap_year(year) && month == 2) {
      day = 1;
      month++;
    }
    if (date == 7 && day == 1) {
      res++;
    }
  }
  printf("%d\n", res);
  return 0;
}
