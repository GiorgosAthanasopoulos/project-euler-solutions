#include <stdio.h>

int isPythagoreanTriplet(int a, int b, int c) { return c * c == a * a + b * b; }

int main(void) {
  printf("[INFO]: Problem: https://projecteuler.net/problem=9\n");
  printf("[INFO]: Description: find the product of the pythagorean triplet "
         "with sum of 1000\n");

  int product = 1;

  for (int a = 0; a < 1000; ++a)
    for (int b = 0; b < 1000; ++b)
      for (int c = 0; c < 1000; ++c)
        if (a < b && b < c && a + b + c == 1000 &&
            isPythagoreanTriplet(a, b, c)) {
          product = a * b * c;
          goto exit;
        }

exit:
  printf("[INFO]: Solution: %d\n", product);
  return 0;
}
