#include "_leetcode_common.c"

#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define MAX(x, y) ((x) > (y) ? (x) : (y))

int rob(int *nums, int numsSize) {
  if (numsSize <= 0) {
    return 0;
  }

  // let dp[n] be the max total money we can get till n-th house
  int *dp = malloc(numsSize * sizeof(*dp));

  dp[0] = nums[0];
  if (numsSize == 1) {
    return dp[0];
  }

  dp[1] = MAX(nums[0], nums[1]);
  for (int i = 2; i < numsSize; ++i) {
    dp[i] = MAX(
        // rob the current house
        dp[i - 2] + nums[i],
        // do not rob the current house
        dp[i - 1]);
  }

  return dp[numsSize - 1];
}

int main(int argc, char *argv[]) {
  return 0;
}
