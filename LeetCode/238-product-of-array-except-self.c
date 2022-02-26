#include "_leetcode_common.c"

int *productExceptSelf(int *nums, int numsSize, int *returnSize) {
  *returnSize = numsSize;
  int *res = malloc(*returnSize * sizeof(*res));
  int *prefix = malloc(*returnSize * sizeof(*res));
  int *suffix = malloc(*returnSize * sizeof(*res));
  int p = 1;

  // prefix product
  p = 1;
  for (int i = 0; i < numsSize; ++i) {
    prefix[i] = p;
    p *= nums[i];
  }

  // suffix product
  p = 1;
  for (int i = numsSize - 1; i >= 0; --i) {
    suffix[i] = p;
    p *= nums[i];
  }

  // answer
  for (int i = 0; i < numsSize; ++i) {
    res[i] = prefix[i] * suffix[i];
  }

  return res;
}

int main(int argc, char *argv[]) {
  int nums_1[] = {1, 2, 3, 4};
  int size_1 = sizeof(nums_1) / sizeof(int);
  int retSize_1 = -1;
  int *res = productExceptSelf(nums_1, size_1, &retSize_1);

  printList(res, size_1);

  return 0;
}
