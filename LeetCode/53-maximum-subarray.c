#include "_leetcode_common.c"

#define MAX(x, y) ((x) > (y) ? (x) : (y))

int maxSubArray(int *nums, int numsSize) {
  int maxSum = nums[0];

  for (int sum = nums[0], i = 1; i < numsSize; ++i) {
    sum = MAX(sum + nums[i], // continue to take the current
              nums[i]);      // drop all previous but only take the current
    maxSum = MAX(maxSum, sum);
  }

  return maxSum;
}

int main(int argc, char *argv[]) {
  return 0;
}
