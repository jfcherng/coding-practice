#include "_leetcode_common.c"

#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) < (y) ? (x) : (y))

int maxProduct(int *nums, int numsSize) {
  int res = nums[0];
  int min = 1;
  int max = 1;

  for (int i = 0; i < numsSize; ++i) {
    int from_min = nums[i] * min;
    int from_max = nums[i] * max;
    min = MIN(MIN(from_min, from_max), nums[i]);
    max = MAX(MAX(from_min, from_max), nums[i]);
    res = MAX(res, max);
  }

  return res;
}

int main(int argc, char *argv[]) {
  return 0;
}
