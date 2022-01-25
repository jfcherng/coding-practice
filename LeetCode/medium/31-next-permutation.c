#include "_leetcode_common.h"

void reverse(int **nums, int l, int r) {
  int *el = *nums;

  while (l < r) {
    int tmp = el[l];
    el[l] = el[r];
    el[r] = tmp;

    ++l;
    --r;
  }
}

void nextPermutation(int *nums, int numsSize) {
  if (numsSize < 2)
    return;

  // from the end side, search for the first index whose value is strictly smaller than its previous visited position
  int drop_idx = numsSize - 2;
  while (drop_idx >= 0 && nums[drop_idx] >= nums[drop_idx + 1]) {
    --drop_idx;
  }

  // from the end side, search for the first index whose value is strictly greater than the one at drop_idx
  int swap_idx = numsSize - 1;
  if (drop_idx >= 0)
    while (swap_idx >= 0 && nums[swap_idx] <= nums[drop_idx]) {
      --swap_idx;
    }

  // nums is reversed sorted, the next permutation is the sorted nums
  if (drop_idx == -1 || swap_idx == -1) {
    reverse(&nums, 0, numsSize - 1);
    return;
  }

  // swap the value at drop_idx and swap_idx
  int tmp = nums[drop_idx];
  nums[drop_idx] = nums[swap_idx];
  nums[swap_idx] = tmp;

  // reverse the part, which is after the drop_idx
  reverse(&nums, drop_idx + 1, numsSize - 1);
}

int main(int argc, char *argv[]) {
  return 0;
}
