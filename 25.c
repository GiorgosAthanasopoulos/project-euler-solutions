#include <limits.h>
#include <stdio.h>
int numPlaces(int n) {
  int r = 1;
  if (n < 0) {
    n = (n == INT_MIN) ? INT_MAX : -n;
  }
  while (n > 9) {
    n /= 10;
    r++;
  }
  return r;
}
int main() {
  int a = 1;
  int b = 1;
  int index = 2;
  while (numPlaces(b) < 1000) {
    int temp = b;
    b = a + b;
    a = b;
    index++;
  }
  printf("%d\n", index - 1);
  return 0;
}
