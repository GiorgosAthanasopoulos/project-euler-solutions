#include <math.h>
#include <stdio.h>
int IsPrime(long a) {
  for (long b = 2; b <= sqrt(a); ++b) {
    if (a % b == 0) {
      return b;
    }
  }
  return a;
}
int main() {
  long a = 600851475143;
  while (a != 1) {
    long b = IsPrime(a);
    if (b < a) {
      a /= b;
    } else {
      printf("%ld\n", a);
      break;
    }
  }
  return 0;
}
