#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef long long ll;

ll max(ll a, ll b) { return a >= b ? a : b; }

int main(int argc, char **argv) {
  printf("[INFO]: Problem: https://projecteuler.net/problem=8\n");
  printf("[INFO]: Description: Find the x adjacent digits in the y-digit "
         "number stored in file z that have the greatest product. What is the "
         "value of this product? (where x, y and z are the first and second "
         "arguments passed to the program)\n");
  printf("[INFO]: Reference: "
         "https://stackoverflow.com/questions/5029840/"
         "convert-char-to-int-in-c-and-c\n");

  if (argc < 4) {
    fprintf(stderr, "[ERROR]: missing arguments: x=number of adjacent digits "
                    "to look for, y=total number of digits in number, "
                    "z=filename where the number is stored (LIMITATION: number "
                    "is stored in a single line)\n");
    return 1;
  }

  int adjacentDigitCount = atoi(argv[1]);
  int numberLength = atoi(argv[2]);
  char *filename = argv[3];

  FILE *file = fopen(filename, "r");

  if (file == NULL) {
    perror("[ERROR]: failed to open input file: ");
    return 1;
  }

  char buf[numberLength];
  fread(buf, sizeof(char), numberLength, file);

  long long maxProduct = 1;

  for (ll i = 0; i <= numberLength - adjacentDigitCount; ++i) {
    ll product = 1;
    for (ll j = i; j < i + adjacentDigitCount; ++j) {
      product *= buf[j] - '0';
    }
    if (product > maxProduct) {
      maxProduct = product;
    }
  }

  printf("[INFO]: Solution: %lld\n", maxProduct);
  fclose(file);
  return 0;
}
