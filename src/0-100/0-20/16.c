#include <stdio.h>
#include <stdlib.h>

#include <gmp.h>

int main(int argc, char **argv) {
  printf("[INFO]: Problem: https://projecteuler.net/problem=16\n");
  printf("[INFO]: Description: What is the sum of the digits of the number "
         "x^y(x and y are provided as first and second program argument)\n");

  if (argc < 3) {
    fprintf(stderr, "[ERROR]: missing arguments: x^y (x=base, y=exponent)\n");
    return 1;
  }

  int base = atoi(argv[1]);
  int exponent = atoi(argv[2]);

  mpz_t number;
  mpz_init(number);
  mpz_ui_pow_ui(number, base, exponent);
  mpz_t sum;
  mpz_init(sum);

  while (mpz_cmp_ui(number, 0)) {
    mpz_t temp;
    mpz_init(temp);
    mpz_mod_ui(temp, number, 10);
    mpz_add(sum, sum, temp);
    mpz_div_ui(number, number, 10);
    mpz_clear(temp);
  }

  printf("[INFO]: Solution: ");
  mpz_out_str(stdout, 10, sum);
  printf("\n");
  mpz_clear(sum);
  mpz_clear(number);
  return 0;
}
