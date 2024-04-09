#include <math.h>
#include <stdio.h>
int get_digit(int n, int k) {
  while (k--) {
    n /= 10;
  }
  return n % 10;
}
int main() {
  int res = 0;
  for (int i = 10000; i <= 99999; ++i) {
    int sum = 0;
    for (int j = 0; j < 5; ++j) {
      sum += pow(get_digit(i, j), 5);
    }
    if (sum == i) {
      res += i;
    }
  }
  printf("%d\n", res);
  return 0;
}
