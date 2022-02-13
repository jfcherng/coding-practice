#include "_leetcode_common.h"
#include <stdio.h>

#define MIN(X, Y) ((X) < (Y) ? (X) : (Y))
#define MAX(X, Y) ((X) > (Y) ? (X) : (Y))

int removeDuplicates(int *nums, int numsSize) {
  if (numsSize < 3) {
    return numsSize;
  }

  int l = 0, r = 0, tail = 0;

  while (r < numsSize) {
    // move "r" to next different int
    while (r < numsSize && nums[r] == nums[l]) {
      ++r;
    }

    for (int i = MIN(l + 2, r) - 1; i >= l; --i) {
      nums[tail++] = nums[i];
    }

    l = r;
  }

  return tail;
}

int main(int argc, char *argv[]) {
  int nums_[] = {1, 1, 1, 2, 2, 3};
  int *nums = &nums_[0];

  int length = removeDuplicates(nums, sizeof(nums_) / sizeof(int));

  printf("length = %d\n", length);
  printList(nums, length);

  return 0;
}
