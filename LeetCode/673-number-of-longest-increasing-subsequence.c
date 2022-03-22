#include "_leetcode_common.c"

typedef struct {
  int cnt;
  int len;
} LIS;

int findNumberOfLIS(int *nums, int numsSize) {
  // dp[i] = information for LIS ends at nums[i]
  LIS *dp = malloc(numsSize * sizeof(*dp));
  dp[0] = (LIS){.cnt = 1, .len = 1};

  LIS res = dp[0];
  for (int i = 1; i < numsSize; ++i) {
    dp[i] = (LIS){.cnt = 1, .len = 0};
    for (int j = i - 1; j >= 0; --j) {
      if (nums[i] <= nums[j] || dp[i].len > dp[j].len)
        continue;
      // update local max
      if (dp[i].len < dp[j].len) {
        dp[i] = dp[j];
      } else {
        dp[i].cnt += dp[j].cnt;
      }
    }
    ++dp[i].len; // self

#ifdef DEBUG
    printf("dp[%d] = {cnt = %d, len = %d}\n", i, dp[i].cnt, dp[i].len);
#endif

    // update global max (i.e., `res`)
    if (res.len < dp[i].len) {
      res = dp[i];
    } else if (res.len == dp[i].len) {
      res.cnt += dp[i].cnt;
    }
  }

  free(dp);
  return res.cnt;
}

int main(int argc, char *argv[]) {
  int res;

  // [1,2,3,1,2,3,1,2,3]
  //  # # #
  //  # #       #
  //  # #             #
  //  #       # #
  //  #       #       #
  //  #             # #
  //        # # #
  //        # #       #
  //        #       # #
  //              # # #
  // [0] = 1 = {cnt = 1, len = 1}
  // [1] = 2 = {cnt = 1, len = 2}
  // [2] = 3 = {cnt = 1, len = 3}
  // [3] = 1 = {cnt = 1, len = 1}
  // [4] = 2 = {cnt = 2, len = 2}
  // [5] = 3 = {cnt = 3, len = 3}
  // [6] = 1 = {cnt = 1, len = 1}
  // [7] = 2 = {cnt = 3, len = 2}
  // [8] = 3 = {cnt = 6, len = 3}
  int nums_1[] = {1, 2, 3, 1, 2, 3, 1, 2, 3};
  res = findNumberOfLIS(nums_1, sizeof(nums_1) / sizeof(int));
  printf("res = %d (10)\n", res);

  return 0;
}
