#include "_leetcode_common.h"

// both ends of the array is negative infinity so there must be at least one peak
int findPeakElement(int *nums, int numsSize) {
  int l = 0, r = numsSize - 1;

  while (l <= r) {
    // trying to move mid to peak
    int mid = (l + r) / 2;

    // is left side increasing?
    if (mid == 0 || nums[mid] > nums[mid - 1]) {
      l = mid + 1;
      // is right side decreasing?
      if (mid == numsSize - 1 || nums[mid] > nums[mid + 1]) {
        return mid;
      }
    } else {
      r = mid;
    }
  }

  return -1;
}

int main(int argc, char *argv[]) {
  return 0;
}
