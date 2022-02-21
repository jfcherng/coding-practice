#include "_leetcode_common.c"

bool canJump(int *nums, int numsSize) {
  if (numsSize <= 0) {
    return false;
  }

  // let dp[i] = i-th index can be reached or not
  bool *dp = malloc(numsSize * sizeof(*dp));
  dp[0] = true;

  for (int i = 1; i < numsSize; ++i) {
    dp[i] = false;
    // i index comes from i-1 index + 1 jump,
    //                    i-2 index + 2 jumps,
    //                    ...,
    //                    or 0 index + i jumps
    for (int j = i - 1; j >= 0; --j) {
      dp[i] |= dp[j] && nums[j] >= i - j;
      if (dp[i]) {
        break;
      }
    }
  }

  return dp[numsSize - 1];
}

int main(int argc, char *argv[]) {
  return 0;
}
