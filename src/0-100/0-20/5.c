#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  printf("[INFO]: Problem: https://projecteuler.net/problem=5\n");
  printf("[INFO]: Description: find the smallest positive number that is "
         "evenly divisible by all of the numbers from x to y where x and y are "
         "the first and second program arguments respectively\n");

  if (argc < 3) {
    fprintf(stderr,
            "[ERROR]: missing argument: x, y (lower and upper limit)\n");
    return 1;
  }

  int lower = atoi(argv[1]);
  int upper = atoi(argv[2]);

  int target = 20;

  while (1) {
    for (int i = upper; i >= lower; --i)
      if (target % i != 0)
        goto endfor;

    break;

  endfor:
    target++;
    continue;
  }

  printf("[INFO]: Solution: %d\n", target);
  return 0;
}
