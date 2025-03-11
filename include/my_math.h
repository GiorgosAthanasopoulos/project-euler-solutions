#ifndef MY_MATH_H_
#define MY_MATH_H_

typedef long long ll;

int isPrime(long long needle);
ll max(ll a, ll b);
int digitCount(int n);
int isPalindromeInt(int target);

#ifdef MY_MATH_IMPLEMENTATION
#include <math.h>
#include <stdlib.h>
#define MY_STRINGS_IMPLEMENTATION
#include "my_strings.h"

int isPrime(long long needle) {
  for (long long i = 2; i <= sqrt(needle); ++i) {
    if (needle % i == 0 && needle != i) {
      return 0;
    }
  }

  return 1;
}

ll max(ll a, ll b) { return a >= b ? a : b; }

int digitCount(int n) { return floor(log10(abs(n))) + 1; }

int isPalindromeInt(int target) {
  int len = digitCount(target);
  char buf[len + 1]; // +1 for null terminator
  sprintf(buf, "%d", target);

  return isPalindrome(buf);
}
#endif // MY_MATH_IMPLEMENTATION

#endif // MY_MATH_H_
