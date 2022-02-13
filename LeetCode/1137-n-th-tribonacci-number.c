#include "_leetcode_common.h"

#define MAX(x, y) ((x) > (y) ? (x) : (y))

int tribonacci(int n) {
  int *dp = malloc(MAX(n + 1, 3) * sizeof(*dp));

  dp[0] = 0;
  dp[1] = 1;
  dp[2] = 1;
  for (int i = 3; i <= n; ++i) {
    dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
  }

  return dp[n];
}

int main(int argc, char *argv[]) {
  return 0;
}
