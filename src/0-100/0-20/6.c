#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  printf("[INFO]: Problem: https://projecteuler.net/problem=6\n");
  printf("[INFO]: Description: find the difference between the sum of the "
         "squares of the first x natural numbers and the square of the sum (x "
         "is the first argument provided to the program)\n");

  if (argc < 2) {
    fprintf(stderr, "[ERROR]: missing argument: ceiling\n");
    return 1;
  }

  int ceiling = atoi(argv[1]);

  long long sumSquares = 0;
  long long sum = 0;

  for (int i = 1; i <= ceiling; ++i) {
    sum += i;
    sumSquares += i * i;
  }

  printf("[INFO]: Solution: %lld\n", llabs(sumSquares - sum * sum));
  return 0;
}
