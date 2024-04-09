#include <stdio.h>
#include <stdlib.h>
int is_abundant(int n) {
  int sum = 0;
  for (int i = 1; i <= n / 2; ++i) {
    if (n % i == 0) {
      sum += i;
    }
  }
  return sum > n;
}
int get_abundants(int *abundants) {
  int index = 0;
  for (int i = 1; i <= 28123; ++i) {
    if (is_abundant(i)) {
      abundants[index++] = i;
    }
  }
  return index;
}
int cannot_write_as_sum_of_two_abundants(int n, int *abundants, int count) {
  for (int i = 0; i < count; ++i) {
    for (int j = i + 1; j < count; ++j) {
      if (abundants[i] + abundants[j] == n) {
        return 0;
      }
    }
  }
  return 1;
}
int main() {
  int *abundants = malloc(sizeof(int) * 28123);
  int abundants_count = get_abundants(abundants);
  int sum = 0;
  for (int i = 1; i <= 28123; ++i) {
    if (cannot_write_as_sum_of_two_abundants(i, abundants, abundants_count)) {
      sum += i;
    }
  }
  printf("%d\n", sum);
  free(abundants);
  return 0;
}
