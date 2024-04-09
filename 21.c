#include <stdio.h>
int d(int n) {
  int sum = 0;
  for (int i = 1; i < n; ++i) {
    if (n % i == 0) {
      sum += i;
    }
  }
  return sum;
}
int main() {
  int sum = 0;
  for (int a = 0; a < 10000; ++a) {
    int b = d(a);
    if (d(b) == a && a != b) {
      sum += a + b;
    }
  }
  printf("%d\n", sum);
  return 0;
}
