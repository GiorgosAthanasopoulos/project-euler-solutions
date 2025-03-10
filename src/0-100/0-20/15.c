#include <stdio.h>
#include <stdlib.h>

typedef long long ll;

ll lattice(int n) {
  ll dp[n + 1][n + 1];

  for (int i = 0; i <= n; ++i) {
    dp[i][0] = 1;
    dp[0][i] = 1;
  }

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
    }
  }

  return dp[n][n];
}

int main(int argc, char **argv) {
  printf("[INFO]: Problem: https://projecteuler.net/problem=15\n");
  printf("[INFO]: Description: Starting in the top left corner of a x x x "
         "grid and only being able to move to the right and down, how many "
         "routes can get you to the bottom right corner?\n");

  if (argc < 3) {
    fprintf(stderr, "[ERROR]: missing arguments: x=grid size\n");
    return 1;
  }

  int size = atoi(argv[1]);

  printf("[INFO]: Solution: %lld\n", lattice(size));
  return 0;
}
