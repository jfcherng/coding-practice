#include "_leetcode_common.h"

#define MAX(x, y) ((x) > (y) ? (x) : (y))

int fib_dp(int n) {
  int *dp = malloc(MAX(n + 1, 2) * sizeof(*dp));

  dp[0] = 0;
  dp[1] = 1;

  for (int i = 2; i <= n; ++i) {
    dp[i] = dp[i - 1] + dp[i - 2];
  }

  return dp[n];
}

int fib(int n) {
  if (n < 2)
    return n;

  int pprev = 0, prev = 1;
  for (int i = 2; i <= n; ++i) {
    int curr = prev + pprev;
    pprev = prev;
    prev = curr;
  }

  return prev;
}

int main(int argc, char *argv[]) {
  return 0;
}
