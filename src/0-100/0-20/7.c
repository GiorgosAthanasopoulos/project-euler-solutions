#define MY_MATH_IMPLEMENTATION
#include "my_math.h"

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  printf("[INFO]: Problem: https://projecteuler.net/problem=7\n");
  printf("[INFO]: Description: What is the x'st/nd/th prime number? (where x "
         "is the "
         "first argument passed to the program)\n");

  if (argc < 2) {
    fprintf(stderr, "[ERROR]: missing argument: target\n");
    return 1;
  }

  int target = atoi(argv[1]);
  int needle = 2;
  int index = 0;

  while (1) {
    if (isPrime(needle)) {
      index++;
      if (index == target)
        break;
    }

    needle++;
  }

  printf("[INFO]: Solution: %d\n", needle);
  return 0;
}
