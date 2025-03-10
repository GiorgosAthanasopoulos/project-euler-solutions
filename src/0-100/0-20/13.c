#include <stdio.h>
#include <stdlib.h>

#include <gmp.h>

typedef long long ll;

int main(int argc, char **argv) {
  printf("[INFO]: Problem: https://projecteuler.net/problem=13\n");
  printf("[INFO]: Description: Work out the first x digits of the sum of the y "
         "z-digit numbers in filename f\n");

  if (argc < 4) {
    fprintf(stderr, "[ERROR]: missing arguments: x=amount of digits to compute "
                    "for sum, y=amount of numbers, z=amount of digits in each "
                    "number, f=filename where number list resides\n");
    return 1;
  }

  int targetDigitCount = atoi(argv[1]);
  int numberCount = atoi(argv[2]);
  int numberDigitCount = atoi(argv[3]);
  char *filename = argv[4];

  FILE *file = fopen(filename, "r");
  if (file == NULL) {
    perror("[ERROR]: failed to open file: ");
    return 1;
  }

  mpz_t numbers[numberCount];
  for (int i = 0; i < numberCount; ++i) {
    mpz_init(numbers[i]);
  }
  int idx = 0;

  while (1) {
    char *buf = NULL;
    size_t len = 0;
    ssize_t read = 0;
    read = getline(&buf, &len, file);
    if (read == -1) {
      break;
    }

    mpz_set_str(numbers[idx++], buf, 10);
    if (buf) {
      free(buf);
    }
  }

  mpz_t sum;
  mpz_init(sum);

  for (int i = 0; i < numberCount; ++i) {
    mpz_add(sum, sum, numbers[i]);
  }

  printf("[INFO]: Solution: ");
  mpz_out_str(stdout, 10, sum);
  printf("\n");
  for (int i = 0; i < numberCount; ++i) {
    mpz_clear(numbers[i]);
  }
  fclose(file);
  return 0;
}
