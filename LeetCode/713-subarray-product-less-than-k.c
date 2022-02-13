#include "_leetcode_common.h"

int numSubarrayProductLessThanK(int *nums, int numsSize, int k) {
  if (k <= 1)
    return 0;

  int res = 0;

  int l = 0, r = 0;
  int prod = 1;
  while (r < numsSize) {
    // count new subarrays who end at "r"
    prod *= nums[r];

    while (prod >= k)
      prod /= nums[l++];

    res += r - l + 1;
    ++r;
  }

  return res;
}

int main(int argc, char *argv[]) {
  return 0;
}
