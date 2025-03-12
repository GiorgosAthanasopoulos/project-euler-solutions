#include <stdio.h>
#include <stdlib.h>

int d(int n) {
  int sum = 0;

  for (int i = 1; i < n; ++i)
    if (n % i == 0)
      sum += i;

  return sum;
}

int contains(int arr[], int size, int n) {
  for (int i = 0; i < size; ++i)
    if (arr[i] == n)
      return 1;

  return 0;
}

int main(int argc, char **argv) {
  printf("[INFO]: Problem: https://projecteuler.net/problem=21\n");
  printf("[INFO]: Description: Evaluate the sum of all the amicable numbers "
         "under x (x is the first program argument).\n");

  if (argc < 2) {
    fprintf(stderr, "[ERROR]: missing argument: limit\n");
    return 1;
  }

  int limit = atoi(argv[1]);
  int sum = 0;

  int prevAmicables[limit];
  int idx = 0;

  for (int i = 1; i < limit; ++i) {
    int di = d(i);
    if (d(di) == i && i != di) {
      if (!contains(prevAmicables, idx, i)) {
        sum += i;
        prevAmicables[idx++] = i;
      }
      if (!contains(prevAmicables, idx, di)) {
        sum += di;
        prevAmicables[idx++] = di;
      }
    }
  }

  printf("[INFO]: Solution: %d\n", sum);
  return 0;
}
