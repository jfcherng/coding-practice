#include "uthash.h"
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *searchRange(int *nums, int numsSize, int target, int *returnSize) {
  int *res = malloc(2 * sizeof(*res));
  *returnSize = 2;

  // binary search
  int l = 0, r = numsSize - 1;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (nums[mid] > target) {
      r = mid - 1;
    } else if (nums[mid] < target) {
      l = mid + 1;
    } else {
      // found target and try expand l and r
      l = r = mid;
      while (l > 0 && nums[l] == nums[l - 1])
        --l;
      while (r < numsSize - 1 && nums[r] == nums[r + 1])
        ++r;
      res[0] = l;
      res[1] = r;
      return res;
    }
  }

  res[0] = res[1] = -1;
  return res;
}

int main(int argc, char *argv[]) {
  return 0;
}
