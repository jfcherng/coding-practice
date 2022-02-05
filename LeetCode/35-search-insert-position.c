#include "_leetcode_common.h"

int searchInsert(int *nums, int numsSize, int target) {
  if (numsSize == 0)
    return 0;

  int l = 0, r = numsSize - 1;

  while (l < r) {
    int mid = (l + r) / 2;

    if (nums[mid] == target) {
      return mid;
    }

    if (nums[mid] > target) {
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }

  return nums[l] < target ? l + 1 : l;
}

int main(int argc, char *argv[]) {
  return 0;
}
