#include <stdio.h>
int oneDigit(int num) { return (num >= 0 && num < 10); }
int isPalUtil(int num, int *dupNum) {
  if (oneDigit(num)) {
    return (num == (*dupNum) % 10);
  }
  if (!isPalUtil(num / 10, dupNum)) {
    return 0;
  }
  *dupNum /= 10;
  return (num % 10 == (*dupNum) % 10);
}
int isPal(int num) {
  if (num < 0) {
    num = -num;
  }
  int dupNum = num;
  return isPalUtil(num, &dupNum);
}
int main() {
  int max = 0;
  for (int i = 999; i >= 100; --i) {
    for (int j = 999; j >= 100; --j) {
      int a = i * j;
      if (isPal(a) && a > max) {
        max = a;
      }
    }
  }
outer:
  printf("%d\n", max);
  return 0;
}
