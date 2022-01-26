#include "_leetcode_common.h"

int climbStairs(int n) {
  int *dp = malloc((n + 2) * sizeof(*dp));
  dp[1] = 1;
  dp[2] = 2;

  for (int i = 3; i <= n; ++i) {
    dp[i] = dp[i - 1] + dp[i - 2];
  }

  return dp[n];
}

int main(int argc, char *argv[]) {
  printf("%d\n", climbStairs(4));
  return 0;
}
