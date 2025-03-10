#include <stdio.h>
#include <stdlib.h>

int collatzLen(long long n) {
  int opCount = 1;
  while (n != 1) {
    if (n % 2 == 0) {
      n = n / 2;
      opCount++;
    } else {
      n = 3 * n + 1;
      opCount++;
    }
  }
  return opCount;
}

int main(int argc, char **argv) {
  printf("[INFO]: Problem: https://projecteuler.net/problem=14\n");
  printf("[INFO]: Description: Find the number that gives the largest length "
         "collatz sequence under x(x provided as first program argument)\n");

  if (argc < 2) {
    fprintf(stderr, "[ERROR]: missing argument: x=ceiling\n");
    return 1;
  }

  int ceiling = atoi(argv[1]);
  int maxChainLen = 0;
  int target = 0;

  for (int i = ceiling - 1; i > 0; --i) {
    printf("[DEBUG]: Checking %d\n", i);
    int iChainLen = collatzLen(i);
    if (iChainLen > maxChainLen) {
      maxChainLen = iChainLen;
      target = i;
    }
  }

  printf("[INFO]: Solution: %d\n", target);
  return 0;
}
