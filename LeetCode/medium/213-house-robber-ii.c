#include "_leetcode_common.h"

#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define MAX(x, y) ((x) > (y) ? (x) : (y))

int house_robber_1(int *nums, int numsSize) {
  if (numsSize == 0) {
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

int rob(int *nums, int numsSize) {
  if (numsSize == 1) {
    return nums[0];
  }
  if (numsSize == 2) {
    return MAX(nums[0], nums[1]);
  }

  // a house is either robbed or not robbed
  //
  //                    / house 0 is robbed => house 1 and n-1 are not robbed => house 2~n-2 is "house robber 1"
  // thus, we can assume
  //                    \ house 0 is not robbed => house 1~n-1 is "house robber 1"
  //
  // by doing so, the circular relationship is break in either assumption.
  return MAX(
      // house 0 is robbed
      nums[0] + house_robber_1(nums + 2, numsSize - 3),
      // house 0 is not robbed
      house_robber_1(nums + 1, numsSize - 1));
}

int main(int argc, char *argv[]) {
  return 0;
}
