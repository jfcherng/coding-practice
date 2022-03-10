#include "_leetcode_common.c"

int lengthOfLIS(int *nums, int numsSize) {
  // `dp[i]` = best ending number for LIS of length `i+1`
  // we want to minimize elements in `dp` so that LIS can be longer
  int *dp = malloc(numsSize * sizeof(*dp));
  int dpSize = 0;

  for (int i = 0; i < numsSize; ++i) {
    // let `r` be the insertion index for `nums[i]` and thus `r` can be `dpSize`
    int l = 0, r = dpSize;

    while (l < r) {
      int mid = l + (r - l) / 2;
      if (nums[i] > dp[mid]) {
        l = mid + 1;
      } else {
        r = mid;
      }
    }

    dp[r] = nums[i];
    dpSize += r == dpSize; // `dpSize` increases if inserting new number rather than replacing old
  }

  free(dp);
  return dpSize;
}

int main(int argc, char *argv[]) {
  int nums_1[] = {10, 9, 2, 5, 3, 7, 101, 18};
  printf("res_1 = %d (4)\n", lengthOfLIS(nums_1, sizeof(nums_1) / sizeof(int)));
  int nums_2[] = {10, 9, 2, 5, 3, 4};
  printf("res_2 = %d (3)\n", lengthOfLIS(nums_2, sizeof(nums_2) / sizeof(int)));
  int nums_3[] = {4};
  printf("res_3 = %d (1)\n", lengthOfLIS(nums_3, sizeof(nums_3) / sizeof(int)));
  int nums_4[] = {};
  printf("res_4 = %d (0)\n", lengthOfLIS(nums_4, sizeof(nums_4) / sizeof(int)));

  return 0;
}
