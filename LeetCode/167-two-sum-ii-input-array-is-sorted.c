#include "_leetcode_common.c"

int *twoSum(int *nums, int numsSize, int target, int *returnSize) {
  *returnSize = 2;
  int *res = malloc(*returnSize * sizeof(*res));

  int l = 0, r = numsSize - 1;
  while (l < r) {
    int sum = nums[l] + nums[r];
    if (sum < target) {
      ++l;
    } else if (sum > target) {
      --r;
    } else {
      // 1-indexed
      res[0] = l + 1;
      res[1] = r + 1;
      break;
    }
  }

  return res;
}

int main(int argc, char *argv[]) {
  return 0;
}
