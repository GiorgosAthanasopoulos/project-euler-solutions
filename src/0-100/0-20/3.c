#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int smallestFactor(long target) {
  if (target <= 1) {
    fprintf(
        stderr,
        "[ERROR]: smallestFactor argument must be a number greater than 1\n");
    exit(1);
  }
  for (long i = 2, end = sqrt(target); i <= end; ++i) {
    if (target % i == 0) {
      return i;
    }
  }
  return target;
}

int isPrime(long long needle) {
  for (long long i = 2; i <= sqrt(needle); ++i) {
    if (needle % i == 0 && needle != i) {
      return 0;
    }
  }

  return 1;
}

int main(int argc, char **argv) {
  printf("[INFO]: Problem: https://projecteuler.net/problem=3\n");
  printf("[INFO]: Description: Find the largest prime factor of the number "
         "provided as the first program argument\n");
  printf("[INFO]: Reference: "
         "https://en.wikipedia.org/wiki/Prime_number\n");
  printf("[INFO]: Reference: "
         "https://github.com/nayuki/Project-Euler-solutions/blob/master/java/"
         "p003.java?ts=4\n");

  if (argc < 2) {
    fprintf(stderr, "[ERROR]: missing argument: target number\n");
    return 1;
  }

  long long target = atoll(argv[1]);

  while (1) {
    long factor = smallestFactor(target);
    if (factor < target) {
      target /= factor;
    } else {
      break;
    }
  }

  printf("[INFO]: Solution: %d\n", target);
  return 0;
}
