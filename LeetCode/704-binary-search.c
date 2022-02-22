#include "_leetcode_common.c"

int search(int *nums, int numsSize, int target) {
  int l = 0, r = numsSize - 1;

  while (l <= r) {
    int m = (l + r) / 2;

    if (nums[m] > target) {
      r = m - 1;
    } else if (nums[m] < target) {
      l = m + 1;
    } else {
      return m;
    }
  }

  return -1;
}

int main(int argc, char *argv[]) {
  return 0;
}
