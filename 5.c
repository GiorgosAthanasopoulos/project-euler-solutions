#include <stdio.h>
int main() {
  int number = 1;
  while (1) {
    for (int i = 1; i <= 20; ++i) {
      if (number % i != 0) {
        break;
      }
      if (i == 20) {
        printf("%d\n", number);
        goto outer;
      }
    }
    number++;
  }
outer:
  return 0;
}
