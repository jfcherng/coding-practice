#include "_leetcode_common.h"

int majorityElement(int *nums, int numsSize) {
  // sorting and return the mid element is obvious...

  // Boyer-Moore Voting Algorithm
  int candidate;
  int cnt = 0;
  for (int i = 0; i < numsSize; ++i) {
    int num = nums[i];
    if (cnt == 0)
      candidate = num;
    cnt += (num == candidate) ? 1 : -1;
  }

  return candidate;
}

int main(int argc, char *argv[]) {
  return 0;
}
