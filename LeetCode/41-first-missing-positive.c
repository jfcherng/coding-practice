#include "_leetcode_common.h"

int firstMissingPositive(int *nums, int numsSize) {
  // using array "nums" itself as a hashset
  // index = hash(N) = N-1 for N <- [1, numsSize]
  for (int i = 0; i < numsSize; ++i) {
    // hash by swapping
    while (nums[i] > 0 && nums[i] <= numsSize && nums[nums[i] - 1] != nums[i]) {
      int tmp = nums[i];
      nums[i] = nums[tmp - 1];
      nums[tmp - 1] = tmp;
    }
  }

  int i = 0;
  while (i < numsSize) {
    if (nums[i] != i + 1)
      break;
    ++i;
  }
  return i + 1;
}

int main(int argc, char *argv[]) {
  int *nums1 = malloc(sizeof(*nums1));
  int nums1_[] = {1, 2, 0};
  nums1 = &nums1_[0];
  printf("%d\n", firstMissingPositive(nums1, 3));
  return 0;
}
