#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  printf("[INFO]: Problem: https://projecteuler.net/problem=1\n");
  printf("[INFO]: Description: find the sum of all of the multiples of 3 and 5 "
         "below the number provided as the first program argument\n");

  if (argc < 2) {
    fprintf(stderr, "[ERROR]: missing parameters: limit\n");
    return 1;
  }

  int limit = atoi(argv[1]);
  int sum = 0;

  for (int i = 1; i < limit; ++i)
    if (i % 3 == 0 || i % 5 == 0)
      sum += i;

  printf("[INFO]: Solution: %d\n", sum);
  return 0;
}
