#include <stdio.h>
int main() {
  long long sum_square = 0;
  long long square_sum = 0;
  for (int i = 1; i <= 100; ++i) {
    sum_square += i * i;
    square_sum += i;
  }
  square_sum *= square_sum;
  printf("%lld\n", square_sum - sum_square);
  return 0;
}
