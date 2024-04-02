#include <math.h>
#include <stdio.h>
int IsPrime(long long number) {
  if (number <= 1) {
    return 0;
  }
  for (int i = 2; i <= sqrt(number); ++i) {
    if (number % i == 0) {
      return 0;
    }
  }
  return 1;
}
int main() {
  int primeNumberCounter = 0;
  long long currentNumber = 0;
  while (primeNumberCounter < 10001) {
    if (IsPrime(currentNumber)) {
      primeNumberCounter++;
    }
    currentNumber++;
  }
  printf("%lld\n", currentNumber - 1);
  return 0;
}
