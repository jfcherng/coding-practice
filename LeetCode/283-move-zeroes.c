#include "_leetcode_common.c"

void moveZeroes(int *nums, int numsSize) {
  int p = numsSize - 1; // the index to store zero

  for (int i = numsSize - 1; i >= 0; --i) {
    if (nums[i] != 0)
      continue;
    // shift
    for (int j = i; j < p; ++j)
      nums[j] = nums[j + 1];
    // append 0
    nums[p--] = 0;
  }
}

int main(int argc, char *argv[]) {
  return 0;
}
