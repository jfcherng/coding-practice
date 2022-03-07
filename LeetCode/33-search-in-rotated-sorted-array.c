#include "_leetcode_common.c"

// [4,5,6,7,8,1,2,3]
// 8

int search(int *nums, int numsSize, int target) {
  // binary search
  int l = 0, r = numsSize - 1;

  while (l <= r) {
    int mid = l + (r - l) / 2;

    if (nums[mid] == target)
      return mid;

    // observation: either [l..mid) or (mid..r] is sorted
    if (
        // (mid..r] is sorted and the target is in (mid..r]
        (nums[mid] < nums[r] && nums[mid] < target && target <= nums[r]) ||
        // [l..mid) is sorted and the target is NOT in [l..mid)
        (nums[mid] > nums[r] && !(nums[l] <= target && target < nums[mid]))) {
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }

  return -1;
}

int main(int argc, char *argv[]) {
  return 0;
}
