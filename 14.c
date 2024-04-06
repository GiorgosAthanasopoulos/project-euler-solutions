#include <stdio.h>
int get_collatz_chain_length(int n) {
  int length = 1;
  while (n != 1) {
    if (n % 2 == 0) {
      n /= 2;
    } else {
      n = 3 * n + 1;
    }
    length++;
  }
  return length - 1;
}
int main() {
  int max_number = 0, max_length = 0;
  for (int i = 999999; i > 0; ++i) {
    int temp = get_collatz_chain_length(i);
    if (temp > max_length) {
      max_length = temp;
      max_number = i;
    }
  }
  printf("%d\n", max_number);
  return 0;
}
