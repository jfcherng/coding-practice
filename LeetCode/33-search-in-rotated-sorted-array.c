#include "_leetcode_common.h"

// [4,5,6,7,8,1,2,3]
// 8

int search(int *nums, int numsSize, int target) {
  // binary search
  int l = 0, r = numsSize - 1;

  while (l <= r) {
    int mid = (l + r) / 2;

    if (nums[mid] == target)
      return mid;

    // either l~mid or mid~r is sorted
    // mid~r is sorted
    if (nums[mid] < nums[r]) {
      // if target is in mid~r
      if (nums[mid] < target && target <= nums[r]) {
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }
    // l~mid is sorted
    else {
      // if target is in l~mid
      if (nums[l] <= target && target < nums[mid]) {
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }
  }

  return -1;
}

int main(int argc, char *argv[]) {
  return 0;
}
