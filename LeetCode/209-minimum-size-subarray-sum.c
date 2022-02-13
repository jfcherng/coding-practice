#include "_leetcode_common.h"

#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) < (y) ? (x) : (y))

int minSubArrayLen(int target, int *nums, int numsSize) {
  int minLen = INT_MAX;

  bool has_ans = false;
  int l = 0, r = 0, sum = 0;
  while (l <= r && r < numsSize) {
    sum += nums[r];

    // found an answer
    while (l <= r && sum >= target) {
      has_ans = true;
      minLen = MIN(minLen, r - l + 1);
      // try to reduce elements
      if (sum - nums[l] >= target) {
        sum -= nums[l++];
      } else {
        break;
      }
    }

    ++r;
  }

  return has_ans ? minLen : 0;
}

int main(int argc, char *argv[]) {
  int nums1[] = {2, 3, 1, 2, 4, 3};
  int *nums1_ = &nums1[0];
  int ans1 = minSubArrayLen(7, nums1_, 6);
  printf("Ans: %d\n", ans1);
  return 0;
}
