#include <math.h>
#include <stdio.h>
int sum_of_digits(int n) {
  int sum = 0;
  while (n != 0) {
    sum += n % 10;
    n /= 10;
  }
  return sum;
}
int main() {
  double res = pow(2, 1000);
  printf("%d\n", sum_of_digits(res));
  return 0;
}
