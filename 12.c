#include <stdio.h>
int get_factors(int number) {
  int factors = 0;
  for (int i = 1; i <= number; ++i) {
    if (number % i == 0) {
      factors++;
    }
  }
  return factors;
}
int get_nth_triangle_number(int n) {
  int sum = 0;
  for (int i = 1; i <= n; ++i) {
    sum += i;
  }
  return sum;
}
int main() {
  int n = 1;
  int triangle_number = get_nth_triangle_number(n);
  int factors = get_factors(triangle_number);
  while (factors < 500) {
    factors = get_factors(triangle_number);
    n++;
    triangle_number = get_nth_triangle_number(n);
    printf("n: %d, triangle_number: %d, factors: %d\n", n, triangle_number,
           factors);
  }
  printf("%d\n", triangle_number);
  return 0;
}
