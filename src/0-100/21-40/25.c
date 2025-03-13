#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>

int mpzLen(mpz_t n) {
    mpz_t cpy;
    mpz_init(cpy);
    mpz_set(cpy, n);

    int len = 0;
    while (mpz_cmp_ui(cpy, 0)) {
        mpz_div_ui(cpy, cpy, 10);
        len++;
    }
    
    mpz_clear(cpy);
    return len;
}

int main(int argc, char **argv) {
    printf("[INFO]: Problem: https://projecteuler.net/problem=25\n");
    printf("[INFO]: Description: What is the first term in the Fibonacci sequence to contain x digits(x is the first program argument)?\n");

    if (argc < 2) {
        fprintf(stderr, "[ERROR]: missing argument: number of digits to look for\n");
        return 1;
    }

    int noDigits = atoi(argv[1]);
    int no = 2;

    mpz_t a, b;
    mpz_inits(a, b, NULL);
    mpz_set_ui(a, 1);
    mpz_set_ui(b, 1);

    while (1) {
        if (mpzLen(b) == noDigits) 
            break;

        mpz_t temp;
        mpz_init(temp);

        mpz_set(temp, b);
        mpz_add(b, b, a);
        mpz_set(a, temp);

        mpz_clear(temp);
        no++;
    }

    printf("[INFO]: Solution: %d\n", no);    
    mpz_clears(a, b, NULL);
    return 0;
}
