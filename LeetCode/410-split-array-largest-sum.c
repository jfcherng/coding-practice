#include "_leetcode_common.c"

// Can `nums` be split into `m` contiguous subarrays whose sums are <= `targetSum` ?
bool canSplit(int *nums, int numsSize, int m, int targetSum) {
  int sum = 0, parts = 1;
  for (int i = 0; i < numsSize; ++i) {
    sum += nums[i];
    if (sum > targetSum) {
      sum = nums[i];
      ++parts;
    }
  }
  return parts <= m;
}

int splitArray(int *nums, int numsSize, int m) {
  int res = -1;

  // `l` = min possible largest split array sum = max(nums)
  // `r` = max possible largest split array sum = sum(nums)
  int l = 0, r = 0;
  for (int i = 0; i < numsSize; ++i) {
    if (l < nums[i])
      l = nums[i];
    r += nums[i];
  }

  while (l <= r) {
    int mid = l + (r - l) / 2;
    if (canSplit(nums, numsSize, m, mid)) {
      res = mid;
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }

  return res;
}

int main(int argc, char *argv[]) {
  int nums1[] = {7, 2, 5, 10, 8};
  printf("res = %d (18)\n", splitArray(nums1, sizeof(nums1) / sizeof(int), 2));

  int nums2[] = {1, 4, 4};
  printf("res = %d (4)\n", splitArray(nums2, sizeof(nums2) / sizeof(int), 3));

  return 0;
}
