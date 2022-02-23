#include "_leetcode_common.c"

int *sortedSquares(int *nums, int numsSize, int *returnSize) {
  *returnSize = numsSize;
  int *res = malloc(*returnSize * sizeof(*res));
  int l = 0, r = numsSize - 1;

  for (int i = numsSize - 1; i >= 0; --i) {
    if (abs(nums[l]) > abs(nums[r])) {
      res[i] = nums[l] * nums[l];
      ++l;
    } else {
      res[i] = nums[r] * nums[r];
      --r;
    }
  }

  return res;
}

int main(int argc, char *argv[]) {
  int nums_1[] = {-4, -1, 0, 3, 10};
  int res_size_1;
  int *res_1 = sortedSquares(nums_1, sizeof(nums_1) / sizeof(int), &res_size_1);
  printList(res_1, res_size_1);

  return 0;
}
