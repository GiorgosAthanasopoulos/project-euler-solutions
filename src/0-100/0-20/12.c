#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef long long ll;

ll getTriangleNumber(ll n) {
  ll sum = 0;
  for (ll i = 1; i <= n; ++i) {
    sum += i;
  }
  return sum;
}

ll getDivisorCount(ll n) {
  ll divisorCount = 0;
  for (ll i = 1; i <= sqrt(n); ++i) {
    if (n % i == 0) {
      divisorCount++;
      if (i != n / i) {
        divisorCount++;
      }
    }
  }
  return divisorCount;
}

int main(int argc, char **argv) {
  printf("[INFO]: Problem: https://projecteuler.net/problem=12\n");
  printf("[INFO]: Description what is the value of the first triangle number "
         "to have other x divisors(where triangle number is the addition of "
         "the nth first numbers) (x is the amount of divisors to look for - "
         "over)?\n");

  if (argc < 2) {
    fprintf(
        stderr,
        "[ERROR]: missing argument: x=amount of divisors to look for (over)\n");
    return 1;
  }

  int divisorTarget = atoi(argv[1]);
  int lookup = 1;

  while (1) {
    long long triangle = getTriangleNumber(lookup++);
    int divisorCount = getDivisorCount(triangle);
    if (divisorCount > divisorTarget) {
      printf("[INFO]: Solution: %lld\n", triangle);
      return 0;
    }
  }

  printf("[INFO]: No solution found\n");
  return 1;
}
