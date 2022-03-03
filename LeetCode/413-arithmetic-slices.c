#include "_leetcode_common.c"

int numberOfArithmeticSlices(int *nums, int numsSize) {
  if (numsSize < 3) {
    return 0;
  }

  int res = 0;

  // let dp[i] = num of arithmetic slices which end at index "i"
  int *dp = calloc(numsSize, sizeof(*dp));
  dp[0] = dp[1] = 0;

  for (int i = 2; i < numsSize; ++i) {
    dp[i] = (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2]) ? dp[i - 1] + 1 : 0;
    res += dp[i];
  }

  return res;
}

int numberOfArithmeticSlices_simplified_1(int *nums, int numsSize) {
  int res = 0;

  // let curr = dp[i], prev = dp[i-1]
  int curr = 0, prev = 0;

  for (int i = 2; i < numsSize; ++i) {
    curr = (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2]) ? prev + 1 : 0;
    res += curr;
    prev = curr;
  }

  return res;
}

int numberOfArithmeticSlices_simplified_2(int *nums, int numsSize) {
  int res = 0;

  int prev = 0;
  for (int i = 2; i < numsSize; ++i) {
    res += (prev = (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2]) ? prev + 1 : 0);
  }

  return res;
}

int main(int argc, char *argv[]) {
  int res = -1;

  int arr_1[] = {1, 2, 3, 4};
  res = numberOfArithmeticSlices(arr_1, sizeof(arr_1) / sizeof(*arr_1));
  printf("res = %d\n", res);

  return 0;
}
