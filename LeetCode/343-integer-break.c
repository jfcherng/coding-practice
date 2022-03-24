#include "_leetcode_common.c"

#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) < (y) ? (x) : (y))

int integerBreak(int n) {
  // dp[i] = max product of `n`
  int *dp = calloc(n + 1, sizeof(*dp)); // all 0s
  dp[2] = 1;                            // n >= 2, this is the trivial case

  for (int i = 3; i <= n; ++i) {
    for (int j = i - 1; j >= 2; --j) {
      dp[i] = MAX(dp[i], dp[j] * (i - j)); // break `j`
      dp[i] = MAX(dp[i], j * (i - j));     // do not break `j`
    }
  }

  int res = dp[n];
  free(dp);
  return res;
}

int main(int argc, char *argv[]) {
  printf("res = %d (36)\n", integerBreak(10));

  return 0;
}
