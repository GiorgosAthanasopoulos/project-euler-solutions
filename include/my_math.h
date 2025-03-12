#ifndef MY_MATH_H_
#define MY_MATH_H_

typedef long long ll;

int isPrime(long long needle);
ll max(ll a, ll b);
int intLen(int n);
int isPalindromeInt(int target);
int sumDigits(int n);
ll factorial(ll n);

#ifdef MY_MATH_IMPLEMENTATION
#define MY_STRINGS_IMPLEMENTATION
#include "my_strings.h"

#include <malloc.h>
#include <math.h>
#include <stdlib.h>

int isPrime(long long needle) {
  for (long long i = 2; i <= sqrt(needle); ++i) {
    if (needle % i == 0 && needle != i) {
      return 0;
    }
  }

  return 1;
}

ll max(ll a, ll b) { return a >= b ? a : b; }

int intLen(int n) { return floor(log10(abs(n))) + 1; }

int isPalindromeInt(int target) {
  int len = intLen(target);
  char buf[len + 1]; // +1 for null terminator
  sprintf(buf, "%d", target);

  return isPalindrome(buf);
}

ll factorial(ll n) {
  if (n <= 1) {
    return 1;
  }
  return n * factorial(n - 1);
}

int sumDigits(int n) {
  int sum = 0;

  while (n != 0) {
    sum += n % 10;
    n /= 10;
  }

  return sum;
}
#endif // MY_MATH_IMPLEMENTATION

#endif // MY_MATH_H_
