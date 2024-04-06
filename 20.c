#include <stdio.h>
int sum_of_digits(int n) {
  int sum = 0;
  while (n != 0) {
    sum += n % 10;
    n /= 10;
  }
  return sum;
}
int factorial(int n) {
  if (n <= 1) {
    return 1;
  }
  return n * factorial(n - 1);
}
int main() {
  int _factorial = factorial(100);
  printf("factorial: %d, sum_of_digits: %d\n", _factorial,
         sum_of_digits(_factorial));
  return 0;
}
