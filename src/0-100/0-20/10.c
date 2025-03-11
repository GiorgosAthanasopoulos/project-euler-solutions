#define MY_MATH_IMPLEMENTATION
#include "my_math.h"

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  printf("[INFO]: Problem: https://projecteuler.net/problem=10\n");
  printf("[INFO]: Description: Find the sum of all primes below x(where x is "
         "the first argument passed to the program)\n");

  if (argc < 2) {
    fprintf(stderr, "[ERROR]: missing argument: target\n");
    return 1;
  }

  long long target = atoll(argv[1]);
  long long sum = 0;

  for (long long i = 2; i < target; ++i)
    if (isPrime(i))
      sum += i;

  printf("[INFO]: Solution: %lld\n", sum);
  return 0;
}
