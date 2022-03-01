#include "_leetcode_common.c"

int *countBits(int n, int *returnSize) {
  *returnSize = n + 1;
  int *dp = calloc(*returnSize, sizeof(*dp));
  dp[0] = 0;

  for (int i = 1; i < *returnSize; ++i) {
    dp[i] = dp[i >> 1] + (i & 1);
  }

  return dp;
}

int main(int argc, char *argv[]) {
  return 0;
}
