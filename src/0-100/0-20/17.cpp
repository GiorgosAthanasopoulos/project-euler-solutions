// CPP is used cuz cstrings are =( (skill issue)
#define MY_MATH_IMPLEMENTATION
#include "my_math.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>

std::string compute(int n) {
  switch (digitCount(n)) {
  case 1:
    switch (n) {
    case 0:
      return "";
    case 1:
      return "one";
    case 2:
      return "two";
    case 3:
      return "three";
    case 4:
      return "four";
    case 5:
      return "five";
    case 6:
      return "six";
    case 7:
      return "seven";
    case 8:
      return "eight";
    case 9:
      return "nine";
    }
    break;
  case 2:
    switch (n / 10) {
    case 1:
      switch (n % 10) {
      case 0:
        return "ten";
      case 1:
        return "eleven";
      case 2:
        return "twelve";
      case 3:
        return "thirteen";
      case 4:
        return compute(n % 10) + "teen";
      case 5:
        return "fifteen";
      case 6:
        return compute(n % 10) + "teen";
      case 7:
        return compute(n % 10) + "teen";
      case 8:
        return compute(n % 10) + "een";
      case 9:
        return compute(n % 10) + "teen";
      }
      break;
    case 2:
      return "twenty" + compute(n % 10);
    case 3:
      return "thirty" + compute(n % 10);
    case 4:
      return "forty" + compute(n % 10);
    case 5:
      return "fifty" + compute(n % 10);
    case 6:
      return "sixty" + compute(n % 10);
    case 7:
      return "seventy" + compute(n % 10);
    case 8:
      return "eighty" + compute(n % 10);
    case 9:
      return "ninety" + compute(n % 10);
    }
    break;
  case 3:
    return compute(n / 100) + (n % 100 == 0 ? "hundred" : "hundredand") +
           compute(n % 100);
  case 4:
    return compute(n / 1000) + "thousand" + compute(n % 1000);
  }

  return "";
}

int main(int argc, char **argv) {
  printf("[INFO]: Problem: https://projecteuler.net/problem=17\n");
  printf(
      "[INFO]: Description: If all the numbers from x to y inclusive were "
      "written out in words, how many letters would be used?(x and y are "
      "passes to the program as the first and second argument respectively)\n");

  if (argc < 3) {
    fprintf(stderr, "[ERROR]: missing arguments: x=start, y=end\n");
    return 1;
  }

  int start = atoi(argv[1]);
  int end = atoi(argv[2]);
  int sum = 0;

  for (int i = start; i <= end; ++i) {
    std::string text = compute(i);
    printf("%d=%s\n", i, text.c_str());
    sum += text.length();
  }

  printf("[INFO]: Solution: %d\n", sum);
  return 0;
}
