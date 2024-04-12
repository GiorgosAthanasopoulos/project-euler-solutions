#include <stdio.h>
int factorial(int n) {
  if (n <= 1) {
    return 1;
  }
  return n * factorial(n - 1);
}
int get_number_of_digits(int n) {
  int sum = 0;
  while (n > 9) {
    n /= 10;
    sum++;
  }
  return sum;
}
int get_digit(int n, int k) {
  while (k--) {
    n /= 10;
  }
  return n % 10;
}
int digits_factorial_sum(int n) {
  int digits = get_number_of_digits(n);
  int sum = 0;
  for (int i = 0; i < digits; ++i) {
    sum += factorial(get_digit(n, i));
  }
  return sum;
}
int main() {
  int n = 3;
  int sum = 0;
  int invalid_numbers_in_a_row = 0;
  while (1) {
    int temp = digits_factorial_sum(n);
    if (n == temp) {
      sum += n;
      invalid_numbers_in_a_row = 0;
      n++;
      continue;
    }
    invalid_numbers_in_a_row++;
    n++;
    if (invalid_numbers_in_a_row > 999999999) {
      break;
    }
  }
  printf("%d\n", sum);
  return 0;
}
