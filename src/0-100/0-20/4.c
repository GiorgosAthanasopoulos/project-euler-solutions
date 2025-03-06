#include <stdio.h>
#include <string.h>

int intLength(int num) {
  if (num == 0)
    return 1;
  int len = 0;
  if (num < 0)
    num = -num; // Handle negative numbers
  while (num > 0) {
    num /= 10;
    len++;
  }
  return len;
}

void reverseStr(char *str) {
  int len = strlen(str);
  for (int i = 0; i < len / 2; i++) {
    char temp = str[i];
    str[i] = str[len - 1 - i];
    str[len - 1 - i] = temp;
  }
}

int isPalindrome(int target) {
  int len = intLength(target);
  char buf[len + 1]; // +1 for null terminator
  sprintf(buf, "%d", target);

  char reverseBuf[len + 1];
  strcpy(reverseBuf, buf);
  reverseStr(reverseBuf);

  return strcmp(buf, reverseBuf) == 0;
}

int main(int argc, char **argv) {
  printf("[INFO]: Problem: https://projecteuler.net/problem=4\n");
  printf("[INFO]: Description: Find the largest palindrome (number that reads "
         "the same both ways) made from the product of two 3-digit numbers\n");
  printf("[INFO]: Reference: "
         "https://stackoverflow.com/questions/3068397/"
         "finding-the-length-of-an-integer-in-c\n");
  printf("[INFO]: Reference: "
         "https://www.geeksforgeeks.org/reverse-string-in-c/\n");

  int largestPalindrome = 0;

  for (int i = 999; i > 99; --i) {
    for (int j = 999; j > 99; --j) {
      int test = i * j;
      if (isPalindrome(test)) {
        if (test > largestPalindrome) {
          largestPalindrome = test;
        }
      }
    }
  }

  if (largestPalindrome == 0) {
    printf("[INFO]: Solution: no solution found\n");
  } else {
    printf("[INFO]: Solution: %d\n", largestPalindrome);
  }
  return 0;
}
