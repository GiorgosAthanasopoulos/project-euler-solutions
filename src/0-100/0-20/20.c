#include <stdio.h>
#include <stdlib.h>

#include <gmp.h>

mpz_t *sumDigitsLarge(mpz_t n) {
  if (!n)
    return NULL;

  mpz_t *res = malloc(sizeof(mpz_t));
  mpz_init(*res);
  mpz_set_ui(*res, 0);

  while (mpz_cmp_ui(n, 0)) {
    mpz_t temp;
    mpz_init(temp);
    mpz_mod_ui(temp, n, 10);

    mpz_add(*res, *res, temp);
    mpz_div_ui(n, n, 10);

    mpz_clear(temp);
  }

  return res;
}

mpz_t *factorialLarge(mpz_t n) {
  mpz_t *res = malloc(sizeof(mpz_t));
  mpz_init(*res);
  mpz_set_ui(*res, 1);

  while (mpz_cmp_ui(n, 0)) {
    mpz_mul(*res, *res, n);
    mpz_sub_ui(n, n, 1);
  }

  return res;
}

int main(int argc, char **argv) {
  printf("[INFO]: Problem: https://projecteuler.net/problem=20\n");
  printf("[INFO]: Description: Find the sum of the digits in the number x!. "
         "(where x is the first program argument)\n");

  if (argc < 2) {
    fprintf(stderr, "[ERROR]: missing argument: number\n");
    return 1;
  }

  int input = atoi(argv[1]);

  mpz_t inputLarge;
  mpz_init(inputLarge);
  mpz_set_ui(inputLarge, input);

  mpz_t *factorial = factorialLarge(inputLarge);
  mpz_out_str(stdout, 10, *factorial);
  printf("\n");

  mpz_t *digitSum = sumDigitsLarge(*factorial);
  mpz_out_str(stdout, 10, *digitSum);
  printf("\n");

  printf("[INFO]: Solution: ");
  mpz_out_str(stdout, 10, *digitSum);
  printf("\n");

  mpz_clear(*digitSum);
  mpz_clear(*factorial);

  mpz_clear(inputLarge);
  free(factorial);
  free(digitSum);
  return 0;
}
