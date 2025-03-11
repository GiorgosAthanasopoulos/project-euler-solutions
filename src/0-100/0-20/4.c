#define MY_MATH_IMPLEMENTATION
#include "my_math.h"

#include <stdio.h>

int main(void) {
  printf("[INFO]: Problem: https://projecteuler.net/problem=4\n");
  printf("[INFO]: Description: Find the largest palindrome (number that reads "
         "the same both ways) made from the product of two 3-digit numbers\n");
  printf("[INFO]: Reference: "
         "https://stackoverflow.com/questions/3068397/"
         "finding-the-length-of-an-integer-in-c\n");
  printf("[INFO]: Reference: "
         "https://www.geeksforgeeks.org/reverse-string-in-c/\n");

  int largestPalindrome = 0;

  for (int i = 999; i > 99; --i)
    for (int j = 999; j > 99; --j) {
      int test = i * j;
      if (isPalindromeInt(test))
        if (test > largestPalindrome)
          largestPalindrome = test;
    }

  if (largestPalindrome == 0)
    printf("[INFO]: Solution: no solution found\n");
  else
    printf("[INFO]: Solution: %d\n", largestPalindrome);
  return 0;
}
