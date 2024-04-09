#include <malloc.h>
#include <math.h>
int not_contains(int *sequence, int size, int n) {
  for (int i = 0; i < size; ++i) {
    if (sequence[i] == n) {
      return 0;
    }
  }
  return 1;
}
int main() {
  int size = 100 * 100;
  int *sequence = malloc(sizeof(int) * size);
  int index = 0;
  for (int a = 2; a <= 100; ++a) {
    for (int b = 2; b <= 100; ++b) {
      int temp = pow(a, b);
      if (not_contains(sequence, size, temp)) {
        sequence[index++] = temp;
      }
    }
  }
  printf("%d\n", index - 1);
  free(sequence);
  return 0;
}
