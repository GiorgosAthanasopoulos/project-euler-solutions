#include <math.h>
#include <stdio.h>
#include <stdlib.h>

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

  if (argc < 2) {
    fprintf(stderr, "[ERROR]: missing argument: target number\n");
    return 1;
  }

  long long target = atoll(argv[1]);

  long long needle = target;

  while (needle > 0) {
    if (target % needle == 0 && isPrime(needle)) {
      break;
    }

    needle--;
  }

  if (needle != 0) {
    printf("[INFO]: Solution: %lld\n", needle);
  } else {
    printf("[INFO]: Solution: no prime factor found\n");
  }
  return 0;
}
