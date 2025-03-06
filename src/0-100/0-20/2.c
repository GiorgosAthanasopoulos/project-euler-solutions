#include <stdio.h>
#include <stdlib.h>
int main(int argc, char **argv) {
  printf("[INFO]: Problem: https://projecteuler.net/problem=2\n");
  printf("[INFO]: Description: Find the sum of even valued fibonacci sequence "
         "numbers that do not exceed the number provided as the first program "
         "argument\n");

  if (argc < 2) {
    fprintf(stderr, "[ERROR]: missing argument: ceiling\n");
    return 1;
  }

  int ceiling = atoi(argv[1]);

  int a = 1;
  int b = 2;
  int sum = 0;

  while (b < ceiling) {
    if (b % 2 == 0) {
      sum += b;
    }

    int temp = b;
    b = a + b;
    a = temp;
  }

  printf("[INFO]: Solution: %d\n", sum);
  return 0;
}
